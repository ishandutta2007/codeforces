#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int fa[maxn], dt[maxn];
vector<int> g[maxn];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    fa[x] = y;
}

int main() {
    int n, m, d; scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < n; ++i) fa[i] = i;
    vector<pair<int, int>> edge;
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        if (x > y) swap(x, y);
        if (x == 0) {
            edge.emplace_back(x, y);
        } else {
            merge(x, y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }
    vector<pair<int, int>> left;
    for (int i = 0; i < (int)edge.size(); ++i) {
        int x = edge[i].first, y = edge[i].second;
        if (find(x) != find(y)) {
            g[x].push_back(y);
            g[y].push_back(x);
            merge(x, y);
        } else {
            left.emplace_back(x, y);
        }
    }
    for (int i = 0; i < (int)left.size() && (int)g[0].size() < d; ++i) {
        int x = left[i].first, y = left[i].second;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if ((int)g[0].size() != d) {
        puts("NO");
        return 0;
    }
    queue<int> q;
    memset(dt, -1, sizeof(dt));
    dt[0] = 0;
    q.push(0);
    puts("YES");
    while (q.size()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < (int)g[x].size(); ++i) {
            int u = g[x][i];
            if (dt[u] == -1) {
                dt[u] = dt[x] + 1;
                printf("%d %d\n", x + 1, u + 1);
                q.push(u);
            }
        }
    }
}