#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;
const int inv2 = (mod+1)/2;
const int maxn = 205;
ll f[maxn],rf[maxn];
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
ll dp[205][205];
void init(int n) {
    f[0] = 1;
    for(int i=1;i<=n;++i) f[i]=f[i-1]*i%mod;
    rf[n] = fpow(f[n],mod-2);
    for(int i=n-1;i>=0;--i) rf[i]=rf[i+1]*(i+1)%mod;
}
ll comb(ll n,ll k){if(n<k||k<0)return 0;return f[n]*rf[k]%mod*rf[n-k]%mod;}
vector<int> g[maxn];
int sz[maxn];
void dfs(int u, int fa) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

ll ans = 0;
vector<ll> path;
void dfs2(int u, int fa, int s) {
    if(u != s) {
        ll tmp = sz[u];
        path.push_back(tmp);
        for(int i = 0; i < path.size(); ++i) {
            int l = i, r = path.size() - 1 - i;
            if(u < s) swap(l, r);
            ans += 1ll * path[i] * dp[l][r] % mod;
        }
        path.pop_back();
    }
    for(int v : g[u]) {
        if(v == fa) continue;
        path.push_back(sz[u] - sz[v]);
        dfs2(v, u, s);
        path.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    init(n);
    for(int i = 1; i <= n; ++i) dp[i][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) * inv2 % mod;
        }
    }
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i) {
        dfs(i, 0);
        dfs2(i, 0, i);
    }
    ans %= mod;
    cout << ans * fpow(n, mod-2) % mod * inv2 % mod << endl;
}