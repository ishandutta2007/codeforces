#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int N = 1e5 + 5;

int n, k, x, y;
int a[N], res[N][40], f[40];
bool ans[N];
vector<int> g[N];

void dfs1(int x, int fa) {
    res[x][0] = a[x];
    for (auto u : g[x])
        if (u != fa) {
            dfs1(u, x);
            rep(i, 0, k - 1) res[x][(i + 1) % k] ^= res[u][i];
        }
}

void dfs2(int x, int fa) {
    int tmp[40];
    rep(i, 0, k - 1) tmp[i] = f[i];
    int num = 0;
    rep(i, k / 2, k - 1) num ^= f[i];
    //cerr << x << " " << num << endl;
    ans[x] = num == 0 ? 0 : 1;

    for (auto u : g[x])
        if (u != fa) {
            rep(i, 0, k - 1) f[(i + 1) % k] = tmp[i] ^ res[u][(i + k - 1) % k] ^ res[u][(i + 1) % k];
            dfs2(u, x);
        }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> k;
    k *= 2;
    rep(i, 1, n - 1) {
        cin >> x >> y;
        g[x].PB(y), g[y].PB(x);
    }
    rep(i, 1, n) cin >> a[i];
    dfs1(1, 0);
    rep(i, 0, k - 1) f[i] = res[1][i];
    dfs2(1, 0);
    rep(i, 1, n) cout << ans[i] << " ";
}