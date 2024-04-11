#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1234567
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b)  {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
int n;
int sz[maxn];
vi g[maxn];
ll dp[maxn];
void dfs(int u, int p) {
    sz[u] = 1;
    for (int v : g[u])
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    dp[1] += sz[u];
}
void dfs1(int u, int p) {
    for (int v : g[u]) {
        if (v != p) {
            dp[v] = dp[u] - sz[u] - sz[v];
            sz[u] -= sz[v];
            sz[v] += sz[u];
            dp[v] += sz[u] + sz[v];
            dfs1(v, u);
            sz[v] -= sz[u];
            sz[u] += sz[v];
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }
    dfs(1, 1);
    dfs1(1, 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) chkmax(ans, dp[i]);
    printf("%lld", ans);
    return 0;
}