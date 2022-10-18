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
        int y = 0;
        auto ask = [&](int x) {
            cout << "? " << x + 1 << endl;
            cin >> x;
            y++;
            x--;
            return x;
        };
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> a(n);
        for (int i = 0; i < n; i++) {
            a[i].emplace_back(i, 0);
        }
        vector<int> b(n);
        vector<int> p(n, -1);
        for (int i = 0; i < n; i++) {
            vector<int> c;
            while (true) {
                int x = ask(i);
                a[x].emplace_back(i, y);
                if (b[x]) {
                    break;
                }
                c.emplace_back(x);
                b[x] = 1;
            }
            int k = (int) c.size();
            for (int j = 0; j < k; j++) {
                p[c[j]] = c[(j + 1) % k];
            }
        }
        cout << "! ";
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                cout << " ";
            }
            cout << p[i] + 1;
        }
        cout << endl;
    }
    return 0;
}