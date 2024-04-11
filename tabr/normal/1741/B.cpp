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
        if (n == 3) {
            cout << -1 << '\n';
            continue;
        } else if (n % 2 == 0) {
            for (int i = n; i >= 1; i--) {
                cout << i << " \n"[i == 1];
            }
        } else {
            cout << "5 4 1 2 3 ";
            for (int i = n; i >= 6; i--) {
                cout << i << " \n"[i == 6];
            }
        }
    }
    return 0;
}