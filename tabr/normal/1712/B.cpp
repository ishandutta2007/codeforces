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
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << '\n';
        } else if (n % 2 == 0) {
            for (int i = 0; i < n; i++) {
                cout << (i ^ 1) + 1 << " \n"[i == n - 1];
            }
        } else {
            cout << "1 ";
            for (int i = 1; i < n; i++) {
                cout << ((i - 1) ^ 1) + 2 << " \n"[i == n - 1];
            }
        }
    }
    return 0;
}