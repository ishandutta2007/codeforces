#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 605, M = N * N;
mt19937 rng(time(0));

int n, m, q, u, v, w, l;
LL w1[N][N], l1[N][N];
LL d[N][N], diff[N][N];

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, n) d[i][j] = INF;
    rep(i, 1, n) d[i][i] = 0;
    rep(i, 1, m) {
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = w;
        w1[u][v] = w1[v][u] = w;
    }
    rep(k, 1, n) rep(i, 1, n) rep(j, i + 1, n) if (d[i][k] + d[k][j] < d[i][j])
        d[i][j] = d[j][i] = d[i][k] + d[k][j];

    cin >> q;
    rep(i, 1, q) {
        cin >> u >> v >> l;
        l1[u][v] = l1[v][u] = l;
    }

    rep(i, 1, n) rep(j, 1, n) diff[i][j] = -INF;
    rep(u, 1, n) rep(v, 1, n) if (l1[u][v]) {
        rep(x, 1, n) diff[u][x] = max(diff[u][x], l1[u][v] - d[v][x]);
    }

    int ans = 0;
    rep(x, 1, n) rep(y, x + 1, n) if (w1[x][y]) {
        bool flag = false;
        rep(u, 1, n) if (d[u][x] + w1[x][y] <= diff[u][y] || d[u][y] + w1[x][y] <= diff[u][x]) {
            flag = true;
            break;
        }
        ans += flag;
    }
    cout << ans << endl;
    return 0;
}