#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n, a, b, da, db, x, y, dia;
int d[N], down[N];
vector<int> g[N];

void dfs(int x, int fa) {
    int ma = 0, ma2 = 0;
    down[x] = 1, d[x] = d[fa] + 1;
    for (auto u : g[x])
        if (u != fa) {
            dfs(u, x);
            down[x] = max(down[x], down[u] + 1);
            if (down[u] > ma)
                ma2 = ma, ma = max(ma, down[u]);
            else if (down[u] > ma2)
                ma2 = down[u];
        }
    dia = max(dia, ma + ma2);
}

int main() {
    cin >> T;
    while (T--) {
        scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
        rep(i, 1, n) g[i].clear();
        rep(i, 1, n - 1) {
            scanf("%d%d", &x, &y);
            g[x].PB(y), g[y].PB(x);
        }
        d[0] = 0, dia = 0;
        dfs(a, 0);
        if (d[b] - 1 <= da || da * 2 >= dia || db <= da * 2)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}