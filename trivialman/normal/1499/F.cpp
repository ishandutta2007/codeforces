#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int N = 5005;

int n, k, x, y;
int dp[N][N], sdp[N][N];
vector<int> g[N];

int dfs(int x, int fa) {
    if (x != 1 && g[x].size() == 1) {
        dp[x][0] = sdp[x][0] = 1;
        return 0;
    }

    int dep = 0;
    dp[x][0] = sdp[x][0] = 1;
    for (auto u : g[x])
        if (u != fa) {
            int du = dfs(u, x);
            rrep(len, min(k, max(dep, du + 1)), 0) {
                int m1 = min(du, min(len - 1, k - len - 1)), m2 = min(dep, min(len - 1, k - len));
                dp[x][len] = 1ll * dp[x][len] * (sdp[u][du] + (m1 >= 0 ? sdp[u][m1] : 0)) % P;
                dp[x][len] = (dp[x][len] + 1ll * (len > 0) * dp[u][len - 1] * (m2 >= 0 ? sdp[x][m2] : 0)) % P;
            }
            sdp[x][0] = dp[x][0];
            rep(i, 1, min(k, max(dep, du + 1))) sdp[x][i] = (sdp[x][i - 1] + dp[x][i]) % P;
            dep = min(k, max(dep, du + 1));
        }
    return dep;
}

int main() {
    cin >> n >> k;
    rep(i, 1, n - 1) {
        cin >> x >> y;
        g[x].PB(y), g[y].PB(x);
    }
    int d = dfs(1, 0);
    cout << sdp[1][d] << endl;
}