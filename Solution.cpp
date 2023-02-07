#include <iostream>
#include <vector>
#include <set>
#include <Queue>
#include <map>
#include <stack>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <sstream>
#include <unordered_set>
#include <bitset>
#include <functional>
#include <numeric>


using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();

    if (m > n)
        return findMedianSortedArrays(nums2, nums1); // make sure nums1 has less members than nums2

    int totalsize = m + n; // take the total size
    int left = 0;
    int right = m;
    while (left <= right)
    {
        int i = left + (right - left) / 2; // i -1 will be last item from left size, i is the first item on right size
        int j = (totalsize + 1) / 2 - i; // same for j-1

        int left1 = (i - 1 >= 0) ? nums1[i-1] : INT_MIN;
        int right1 = (i < m) ? nums1[i] : INT_MAX;

        int left2 = (j - 1 >= 0) ? nums2[j-1] : INT_MIN;
        int right2 = (j < n) ? nums2[j] : INT_MAX;

        if (left1 <= right2 && left2 <= right1)
        {
            if (totalsize % 2)
                return max(left1, left2);
            else
                return (double)(max(left1, left2) + min(right1, right2)) / 2;
        }
        else if (left2 > right1) // if left partition last number greater  than right partition first number of the other array
            //we take less from the target array. Here means we take more on the first array but less on the second array
            left = i + 1; // main left and right are referred to the first array so we add more by change the left to mid + 1 
        else
            right = i - 1;// otherwise
    }

    return 0;
}
int main()  
{
   
    

    vector<int> nums1 = { 1, 2 }, nums2 = { 3,4};
    double res = findMedianSortedArrays(nums1, nums2);
    return 0;

}
