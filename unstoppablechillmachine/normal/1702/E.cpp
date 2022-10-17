#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        bool ok = true;
        vector<int> cnt(n + 1);
        vector<vector<int>> have(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            if (a[i] == b[i]) {
                ok = false;
            }
            cnt[a[i]]++;
            cnt[b[i]]++;
            have[a[i]].push_back(i);
            have[b[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > 2) {
                ok = false;
            }
        }
        vector<vector<int>> g(n);
        for (int i = 1; i <= n; i++) {
            if (have[i].size() == 2) {
                g[have[i][0]].push_back(have[i][1]);
                g[have[i][1]].push_back(have[i][0]);
            }
        }
        vector<int> color(n);
        function<void(int, int)> dfs = [&](int v, int cl) {
            color[v] = cl;
            for (auto u : g[v]) {
                if (!color[u]) {
                    dfs(u, 3 - cl);
                } else if (color[u] != 3 - cl) {
                    ok = false;
                }
            }
        };
        for (int i = 0; i < n; i++) {
            if (!color[i]) {
                dfs(i, 1);
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}