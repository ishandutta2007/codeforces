#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int dt[maxn];
vector<int> g[maxn];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int s = -1;
    for (int i = 0; i < n; ++i) {
        if (s == -1 || (int)g[i].size() > (int)g[s].size())
            s = i;
    }
    queue<int> q;
    memset(dt, -1, sizeof(dt));
    dt[s] = 0;
    q.push(s);
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