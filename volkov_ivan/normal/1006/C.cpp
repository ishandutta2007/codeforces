#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long arr[n];
    int r;
    for (int i = 0; i < n; i++) cin >> arr[i];
    r = n;
    long long ans = 0, now = 0, now_r = 0;
    for (int l = 0; l < n; l++) {
        now += arr[l];
        while (r > l + 1 && now_r < now) {
            r--;
            now_r += arr[r];
        }
        if (l < r && now == now_r) ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}