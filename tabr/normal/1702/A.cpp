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
        long long m;
        cin >> m;
        long long k = 1;
        while (m >= 10 * k) {
            k *= 10;
        }
        cout << m - k << '\n';
    }
    return 0;
}