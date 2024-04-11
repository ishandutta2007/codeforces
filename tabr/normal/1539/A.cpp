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
        long long n, x, t;
        cin >> n >> x >> t;
        long long s = t / x;
        s = min(s, n - 1);
        cout << (n - s) * s + s * (s - 1) / 2 << '\n';
    }
    return 0;
}