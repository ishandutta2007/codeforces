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
        int k;
        cin >> k;
        int l = 100 - k;
        int g = gcd(k, l);
        k /= g;
        l /= g;
        cout << k + l << '\n';
    }
    return 0;
}