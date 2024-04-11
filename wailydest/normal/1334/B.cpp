#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    
    int n, x;
    while (t--) {
        scanf("%d%d", &n, &x);
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
        sort(arr.begin(), arr.end(), greater<int>());
        long long sum = 0;
        int i;
        for (i = 0; i < n; ++i) {
            sum += arr[i];
            if (sum / (i + 1) < x) break;
        }
        printf("%d\n", i);
    }
    return 0;
}