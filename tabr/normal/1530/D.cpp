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
        vector<int> a(n);
        vector<int> deg(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            deg[a[i]]++;
        }
        vector<int> b(n, -1);
        auto dfs = [&](auto &&self, int v, int root) -> void {
            int to = a[v];
            if (b[to] != -1) {
                b[v] = root;
                return;
            }
            b[v] = to;
            self(self, to, root);
        };
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                dfs(dfs, i, i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i] == -1) {
                dfs(dfs, i, i);
            }
        }
        vector<int> c;
        int d = -1;
        for (int i = 0; i < n; i++) {
            if (b[i] == i) {
                c.emplace_back(i);
                b[i] = -1;
            } else if (b[i] != a[i]) {
                d = i;
            }
        }
        if (!c.empty()) {
            for (int i = 0; i + 1 < (int) c.size(); i++) {
                b[c[i]] = c[i + 1];
            }
            b[c.back()] = b[d];
            b[d] = c[0];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                ans++;
            }
        }
        cout << ans << '\n';
        for (int i : b) {
            cout << i + 1 << " ";
        }
        cout << '\n';
    }
    return 0;
}