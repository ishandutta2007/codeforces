#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k, w;
const int K = 1005, N = 11;
char map[K][N][N];

int fa[K];

int find(int u) {
    return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    fa[u] = v;
}

vector<int> go[K];

bool vis[K];

void dfs(int u) {
    vis[u] = true;
    for (int j = 0; j < (int)go[u].size(); ++j) {
        int v = go[u][j];
        if (vis[v]) {
            continue;
        }
        printf("%d %d\n", v, u);
        dfs(v);
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &w);
    vector<pair<int, pair<int, int> > > edge;
    for (int i = 0; i < k; ++i) {
        edge.push_back(make_pair(n * m, make_pair(0, i + 1)));
        for (int j = 0; j < n; ++j) {
            scanf("%s", map[i][j]);
        }
    }
    for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {
            int cost = 0;
            for (int x = 0; x < n && cost < n * m; ++x) {
                for (int y = 0; y < m && cost < n * m; ++y) {
                    cost += (map[i][x][y] != map[j][x][y]) * w;
                }
            }
            if (cost < n * m) {
                edge.push_back(make_pair(cost, make_pair(i + 1, j + 1)));
            }
        }
    }
    for (int i = 0; i <= k; ++i) {
        fa[i] = i;
    }
    int ans = 0;
    sort(edge.begin(), edge.end());
    for (int i = 0; i < (int)edge.size(); ++i) {
        int c = edge[i].first, u = edge[i].second.first, v = edge[i].second.second;
        if (find(u) != find(v)) {
            ans += c;
            merge(find(u), find(v));
            go[u].push_back(v);
            go[v].push_back(u);
        }
    }
    printf("%d\n", ans);
    dfs(0);
    return 0;
}