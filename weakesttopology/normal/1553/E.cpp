#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            --p[i];
        }
        vector<int> cnt(n);
        for (int i = 0; i < n; ++i) {
            int x = i < p[i] ? (n - p[i]) + i : i - p[i];
            ++cnt[x];
        }
        vector<int> ks;
        for (int x = 0; x < n; ++x) {
            if (cnt[x] >= n - 2 * m) {
                auto q = p;
                rotate(begin(q), begin(q) + x, end(q));
                int cycles = 0;
                vector<bool> vis(n);
                for (int u = 0; u < n; ++u) {
                    if (vis[u]) continue;
                    ++cycles;
                    for (int v = u; not vis[v]; vis[v] = true, v = q[v]);
                }
                if (n - cycles <= m) ks.push_back(x);
            }
        }
        cout << size(ks);
        for (auto k : ks) {
            cout << " " << k;
        }
        cout << '\n';
    }
    exit(0);
}