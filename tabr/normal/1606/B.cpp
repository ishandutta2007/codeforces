#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long n, k;
        cin >> n >> k;
        long long now = 1;
        long long ans = 0;
        while (now < n) {
            if (now < k) {
                now += now;
                ans++;
            } else {
                long long need = n - now;
                ans += (need + k - 1) / k;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}