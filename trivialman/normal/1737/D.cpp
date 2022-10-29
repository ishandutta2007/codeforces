#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 2e18;
const int N = 505;
mt19937 rng(time(0));

int T, n, m, x, y, z;
LL g[N][N], d[N][N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        rep(i, 1, n) rep(j, 1, n) d[i][j] = i == j ? 0 : INF;
        rep(i, 1, m) cin >> x >> y >> z, d[x][y] = d[y][x] = min(d[x][y], 1ll * z);
        rep(i, 1, n) rep(j, 1, n) g[i][j] = i == j ? 0 : (d[i][j] < INF ? 1 : INF);
        rep(k, 1, n) rep(i, 1, n) rep(j, i + 1, n) g[i][j] = g[j][i] = min(g[i][j], g[i][k] + g[k][j]);
        LL ans = INF;
        // rep(i, 1, n) cerr << i << " " << g[1][i] << " " << g[i][n] << "\n";
        // cerr << endl;
        rep(i, 1, n) rep(j, i + 1, n) if (d[i][j] < INF) {
            LL t = min(g[1][i] + g[j][n] + 1, g[1][j] + g[i][n] + 1);
            rep(k, 1, n)
                t = min(t, min(g[i][k], g[j][k]) + g[1][k] + g[k][n] + 2);
            ans = min(ans, d[i][j] * t);
        }
        cout << ans << "\n";
    }
    return 0;
}