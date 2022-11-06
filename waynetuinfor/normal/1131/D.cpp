#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
char s[maxn][maxn];
vector<pair<int, int>> g[maxn];
int d[maxn], upd[maxn], inq[maxn];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    function<void(int, int, int)> add_edge = [&](int i, int j, int w) {
        g[i].emplace_back(j, w);
    };
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '<') 
                add_edge(i, j + n, 1);
            if (s[i][j] == '>') 
                add_edge(j + n, i, 1);
            if (s[i][j] == '=') {
                add_edge(i, j + n, 0);
                add_edge(j + n, i, 0);
            }
        }
    }
    for (int i = 0; i < n + m; ++i) 
        add_edge(n + m, i, 0);
    queue<int> q;
    for (int i = 0; i < n + m; ++i) d[i] = -1e9;
    q.push(n + m);
    inq[n + m] = true;
    while (q.size()) {
        int x = q.front(); q.pop();
        inq[x] = false;
        for (int i = 0; i < (int)g[x].size(); ++i) {
            int u = g[x][i].first, w = g[x][i].second;
            if (d[u] < d[x] + w) {
                d[u] = d[x] + w;
                if (++upd[u] > n + m) {
                    puts("No");
                    return 0;
                }
                if (!inq[u]) {
                    inq[u] = true;
                    q.push(u);
                }
            }
        }
    }
    puts("Yes");
    for (int i = 0; i < n; ++i) printf("%d ", d[i] + 1);
    puts("");
    for (int i = n; i < n + m; ++i) printf("%d ", d[i] + 1);
    puts("");
}