#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        int n;
        cin >> n;
        if (n >= 31) {
            cout << "YES" << '\n';
            if (n == 36) {
                cout << "5 6 10 15" << '\n';
            } else if (n == 40) {
                cout << "6 15 14 5" << '\n';
            } else if (n == 44) {
                cout << "6 7 10 21" << '\n';
            } else {
                cout << "6 10 14 " << n - 30 << '\n';
            }
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}