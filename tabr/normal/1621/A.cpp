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
        int n, k;
        cin >> n >> k;
        if ((n + 1) / 2 < k) {
            cout << -1 << '\n';
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j && i % 2 == 0 && k > 0) {
                        k--;
                        cout << "R";
                    } else {
                        cout << ".";
                    }
                }
                cout << '\n';
            }
        }
    }
    return 0;
}