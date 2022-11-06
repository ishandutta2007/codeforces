#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
vector<int> g[maxn];
int deg[maxn], pt[maxn], pos[maxn];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
        if (x < y) ++deg[x];
        else ++deg[y];
    }
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> ans;
        for (const int &u : g[i]) {
            if (u > i) continue;
            ans.emplace_back(i, pt[u]++);
        }
        pos[i] = (i == 0 ? 0 : pos[i - 1] + 2 + deg[i - 1]);
        pt[i] = pos[i];
        for (int j = 0; j < deg[i] + 1; ++j) ans.emplace_back(i, pos[i] + j);
        printf("%d\n", (int)ans.size());
        for (int j = 0; j < (int)ans.size(); ++j)
            printf("%d %d\n", ans[j].first + 1, ans[j].second + 1);
    }
    return 0;
}