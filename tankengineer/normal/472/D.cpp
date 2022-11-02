#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2005;

int n, d[N][N];

long long g[N][N], dep[N];

vector<pair<int, int> > e[N];

int fa[N];

int find(int u) {
    return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    fa[u] = v;
}

vector<int> ord;

int in[N], out[N], len[N];

void dfs(int u, int fa) {
    in[u] = ord.size();
    ord.push_back(u);
    for (int i = 0; i < (int)e[u].size(); ++i) {
        int v = e[u][i].first;
        if (v == fa) {
            continue;
        }
        len[v] = e[u][i].second;
        dep[v] = dep[u] + e[u][i].second;
        ::fa[v] = u;
        dfs(v, u);
    }
    out[u] = ord.size();
}

int main() {
    scanf("%d", &n);
    vector<pair<int, pair<int, int> > > edge;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &d[i][j]);
        }
    }
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j && d[i][j] != 0) {
                flag = false;
            }
            if (i != j && d[i][j] == 0) {
                flag = false;
            }
            if (d[i][j] != d[j][i]) {
                flag = false;
            }
            if (i < j) {
                edge.push_back(make_pair(d[i][j], make_pair(i, j)));
            }
        }
    }
    if (!flag) {
        puts("NO");
        return 0;
    }
    sort(edge.begin(), edge.end());
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
    }
    for (int i = 0; i < (int)edge.size(); ++i) {
        int cost = edge[i].first, u = edge[i].second.first, v = edge[i].second.second;
        if (find(u) == find(v)) {
            continue;
        }
        merge(find(u), find(v));
        e[u].push_back(make_pair(v, cost));
        e[v].push_back(make_pair(u, cost));
    }
    dep[0] = 0;
    fa[0] = -1;
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        g[0][i] = dep[i];
    }
    for (int i = 1; i < n; ++i) {
        int u = ord[i];
        for (int j = 0; j < n; ++j) {
            int v = j;
            bool isson = in[u] <= in[v] && out[v] <= out[u];
            if (isson) {
                g[u][v] = g[fa[u]][v] - len[u];
            } else {
                g[u][v] = g[fa[u]][v] + len[u];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] != d[i][j]) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}