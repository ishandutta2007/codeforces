#include <bits/stdc++.h>
using namespace std;

const int kN = 1e5 + 5;
vector<int> g[kN];
bool v[kN];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
        g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
    }

    set<int> s;
    for (int i = 0; i < n; ++i) s.insert(i);
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (!s.count(i)) continue;
        queue<int> q;
        q.push(i);
        s.erase(i);
        ans += 1;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (auto it = s.begin(); it != s.end(); ) {
                if (!binary_search(g[x].begin(), g[x].end(), *it)) {
                    q.push(*it);
                    it = s.erase(it);
                } else {
                    it = next(it);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}