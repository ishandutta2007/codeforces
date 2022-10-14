#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b)  {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 105;
int n, k;
int cnt[maxn];
int dp[maxn][maxn];
vi g[maxn];
void dfs(int u, int p, int dep) {
    cnt[dep]++;
    for (int v : g[u])
        if (v != p) dfs(v, u, dep + 1);
}
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v; scanf("%d%d", &u, &v);
            g[u].pb(v); g[v].pb(u);
        }
        if (k == 2) {
            printf("%d\n", n * (n - 1) / 2);
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                for (int x = 0; x <= n; x++)
                    dp[x][j] = (x == 0 ? 1 : 0);
            for (int u : g[i]) {
                for (int j = 1; j <= n; j++) cnt[j] = 0;
                dfs(u, i, 1);
                for (int j = n; j >= 1; j--) {
                    for (int x = 0; x <= n; x++) {
                        dp[j][x] = (dp[j][x] + dp[j - 1][x] * 1LL * cnt[x]) % mod;
                    }
                }
            }
            for (int x = 0; x <= n; x++) {
                ans = (ans + dp[k][x]) % mod;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}