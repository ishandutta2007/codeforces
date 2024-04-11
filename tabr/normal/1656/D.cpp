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
        if (__builtin_popcountll(n) == 1) {
            cout << -1 << '\n';
        } else {
            long long t = 2;
            while (n % 2 == 0) {
                n /= 2;
                t *= 2;
            }
            cout << min(n, t) << '\n';
        }
    }
    return 0;
}