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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[y].emplace_back(x);
        }
        vector<int> col(n);
        for (int i = 0; i < n; i++) {
            for (int j : g[i]) {
                if (col[j] == 1) {
                    col[i] = 2;
                    break;
                }
                if (col[j] == 0) {
                    col[i] = 1;
                }
            }
        }
        vector<int> a;
        for (int i = 0; i < n; i++) {
            if (col[i] == 2) {
                a.emplace_back(i + 1);
            }
        }
        cout << a.size() << '\n';
        for (int i : a) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}