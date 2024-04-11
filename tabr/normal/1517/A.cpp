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
        long long n;
        cin >> n;
        long long k = 2050;
        if (n % k != 0) {
            cout << -1 << '\n';
            continue;
        }
        n /= k;
        long long ans = 0;
        while (n) {
            ans += n % 10;
            n /= 10;
        }
        cout << ans << '\n';
    }
    return 0;
}