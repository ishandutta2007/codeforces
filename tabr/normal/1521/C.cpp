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
        auto ask = [&](int t, int i, int j, int x) {
            cout << "? " << t << " " << i + 1 << " " << j + 1 << " " << x << endl;
            int k;
            cin >> k;
            return k;
        };
        int x = n - 1;
        for (int i = 0; i + 1 < n; i += 2) {
            int p = ask(2, i, i + 1, 1);
            if (p == 1) {
                x = i;
                break;
            } else if (p == 2) {
                p = ask(2, i + 1, i, 1);
                if (p == 1) {
                    x = i + 1;
                    break;
                }
            }
        }
        debug(x);
        vector<int> p(n, 1);
        for (int i = 0; i < n; i++) {
            if (i == x) {
                continue;
            }
            p[i] = ask(1, x, i, n - 1);
        }
        cout << "! ";
        for (int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    return 0;
}