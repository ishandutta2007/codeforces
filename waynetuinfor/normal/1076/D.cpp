#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
const long long inf = 1e18;
vector<tuple<int, int, int>> g[maxn];
long long d[maxn];
int us[maxn], ed;
bool v[maxn], st[maxn], del[maxn];

void dfs(int x, int p, int k) {
    for (const auto &e : g[x]) {
        int u = get<0>(e), i = get<2>(e);
        if (!st[i]) continue;
        if (u == p) continue;
        dfs(u, x, k);
        if (ed > k) --ed, del[i] = true;
    }
}

int main() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int x, y, w; scanf("%d%d%d", &x, &y, &w);
        --x, --y;
        g[x].emplace_back(y, w, i);
        g[y].emplace_back(x, w, i);
    }
    fill_n(d, n, inf);
    memset(us, -1, sizeof(us));
    d[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, 
                   greater<pair<long long, int>>> pq;
    pq.emplace(0, 0);
    while (pq.size()) {
        int x = pq.top().second; pq.pop();
        if (v[x]) continue;
        v[x] = true;
        for (const auto &e : g[x]) {
            int u, w, i; tie(u, w, i) = e;
            if (d[u] > d[x] + w) {
                us[u] = i;
                d[u] = d[x] + w;
                pq.emplace(d[u], u);
            }
        }
    }
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (~us[i]) res.push_back(us[i]), st[us[i]] = true;
    }
    ed = n - 1;
    dfs(0, -1, k);
    printf("%d\n", ed);
    for (int i = 0; i < (int)res.size(); ++i) {
        if (!del[res[i]]) printf("%d ", res[i] + 1);
    }
    puts("");
    return 0;
}