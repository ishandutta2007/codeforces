#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

#define size(v) (int(v.size()))
const int MAXN = 200200, inf = 1e9;

int n, m;
vector <int> E[MAXN];
int cur[MAXN];

bool vis[MAXN]; int ans[MAXN];
struct node { int val, id; bool operator < (const node &t) const { return val > t.val; } };
priority_queue <node> pq;

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= m; i++) {
        int u = read(), v = read();
        E[v].push_back(u); ++cur[u];
    }
    for (i = 1; i <= n; i++) ans[i] = inf;
    ans[n] = 0, pq.push({0, n});
    while (!pq.empty()) {
        int x = pq.top().id; pq.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (auto i: E[x]) {
            --cur[i];
            int val = ans[x] + cur[i] + 1;
            if (val < ans[i]) ans[i] = val, pq.push({val, i});
        }
    }
    printf("%d\n", ans[1]);
    return 0;
}