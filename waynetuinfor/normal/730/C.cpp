#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
vector<int> graf[maxn];
int d[maxn][maxn];
int qu[maxn], l, r;
int k[maxn], c[maxn], p[maxn];

void bfs(int g) {
    d[g][g] = 0;
    l = 0, r = 0;
    qu[r++] = g;
    while (l < r) {
        int x = qu[l++];
        for (int i = 0; i < graf[x].size(); ++i) {
            int u = graf[x][i];
            if (d[g][u] == -1) d[g][u] = d[g][x] + 1, qu[r++] = u;
        }
    }
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        graf[u].push_back(v), graf[v].push_back(u);
    }
    int w; scanf("%d", &w);
    for (int i = 0; i < w; ++i) scanf("%d %d %d", &c[i], &k[i], &p[i]);
    vector<int> o(w); iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](const int &i, const int &j) { return p[i] < p[j]; });
    memset(d, -1, sizeof(d));
    int q; scanf("%d", &q);
    while (q--) {
        int g, r, a; scanf("%d %d %d", &g, &r, &a);
        if (d[g][g] == -1) bfs(g);
        function<bool(int)> check = [&](const int &t) {
            vector<int> v;
            for (int i = 0; i < w; ++i) if (d[g][c[o[i]]] <= t && d[g][c[o[i]]] != -1) v.push_back(o[i]);
            int s = 0;
            long long pr = 0;
            for (int i = 0; i < v.size() && s < r; ++i) {
                int need = min(r - s, k[v[i]]);
                pr += need * 1ll * p[v[i]];
                s += need;
            }
            if (s < r) return false;
            return pr <= a;
        };
        int d = 15, ans = n + 1; 
        while (d--) if (ans - (1 << d) >= 0) if (check(ans - (1 << d))) ans -= (1 << d);
        if (ans == n + 1) ans = -1;
        printf("%d\n", ans);
    }
}