#include <iostream>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <functional>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    
    int n;
    while (t--) {
        scanf("%d", &n);
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
        sort(arr.begin(), arr.end());
        int m = (n - 1) / 2;
        for (int i = 0; i < n; ++i) {
            m = m + i * ((i & 1) * 2 - 1);
            printf("%d ", arr[m]);
        }
        printf("\n");
    }
    return 0;
}