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
        long long s, n, k;
        cin >> s >> n >> k;
        if (k > s) {
            cout << "NO" << '\n';
        } else if (k == s) {
            cout << "YES" << '\n';
        } else {
            long long m = n;
            m += n / k * k;
            if (m > s) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}