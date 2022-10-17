#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    int diff = 1, large = 1, largest = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[i - 1]) {
            ++diff;
            largest = max(large, largest);
            large = 1;
        }
        else ++large;
    }
    largest = max(large, largest);
    printf("%d\n", max(min(diff, largest - 1), min(diff - 1, largest)) );
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}