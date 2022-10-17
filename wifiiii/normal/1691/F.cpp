#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
ll inv(ll a) {ll u=0,v=1,b=mod;while(a) {ll t=b/a;b-=t*a,u-=t*v;swap(a,b);swap(u,v);}u%=mod;if(u<0)u+=mod;return u;}
struct mint {
    int x;
    mint():x(0) {}
    mint(int x):x(x) {if(x>=mod||x<-mod)x%=mod;if(x<0)x+=mod;this->x=x;}
    mint(ll x):x() {if(x>=mod||x<-mod)x%=mod;if(x<0)x+=mod;this->x=x;}
    mint& operator -=(const mint &rhs) {x -= rhs.x; if(x < 0) x += mod; return *this;}
    mint& operator +=(const mint &rhs) {x += rhs.x; if(x >= mod) x -= mod; return *this;}
    mint& operator *=(const mint &rhs) {x = (ll)x * rhs.x % mod; return *this;}
    mint& operator /=(const mint &rhs) {x = (ll)x * inv(rhs.x) % mod; return *this;}
    bool operator < (const mint& rhs) {return x < rhs.x;}
    bool operator == (const mint& rhs) {return x == rhs.x;}
    bool operator != (const mint& rhs) {return x != rhs.x;}
    mint operator -() {return mint(-x);}
    friend mint operator +(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret += rhs;}
    friend mint operator -(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret -= rhs;}
    friend mint operator *(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret *= rhs;}
    friend mint operator /(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret /= rhs;}
    friend ostream& operator <<(ostream &os, const mint &rhs) {os << rhs.x; return os;}
    friend istream& operator >>(istream &is, mint &rhs) {ll a; is >> a; rhs = a; return is;}
};
mint fpow(mint a,ll b){mint r=1;for(;b;b>>=1){if(b&1)r=r*a;a=a*a;}return r;}
mint comb(int n,int k) {
    if(n<k||k<0)return 0;
    static vector<mint> f(1,1), rf(1,1);
    if(f.size()<=n) {
        int p=f.size();
        f.resize(n+1),rf.resize(n+1);
        for(int i=p;i<=n;++i) f[i]=f[i-1]*i;rf[n]=1/f[n];
        for(int i=n-1;i>=p;--i) rf[i]=rf[i+1]*(i+1);
    }
    return f[n]*rf[k]*rf[n-k];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> sz(n); vector<mint> dp(n);
    mint sum = 0;
    function<void(int, int)> dfs = [&](int u, int fa) {
        sz[u] = 1;
        mint x = 0;
        for(int v : g[u]) {
            if(v == fa) continue;
            dfs(v, u);
            sz[u] += sz[v];
            x += comb(sz[v], k);
        }
        dp[u] = comb(sz[u], k) - x;
    };
    mint ans = 0;
    dfs(0, -1);
    for(int i = 0; i < n; ++i) sum += dp[i] * sz[i];
    function<void(int, int)> dfs2 = [&](int u, int fa) {
        ans += sum;
        mint psum = sum;
        for(int v : g[u]) {
            if(v == fa) continue;
            sum -= dp[u] * sz[u];
            sum -= dp[v] * sz[v];

            auto p1 = dp[u], p2 = dp[v];
            auto s1 = sz[u], s2 = sz[v];

            dp[u] = dp[u] - comb(sz[u], k) + comb(sz[u] - sz[v], k) + comb(sz[v], k);
            sz[u] = sz[u] - sz[v];
            sum += dp[u] * sz[u];

            dp[v] = dp[v] - comb(sz[v], k) + comb(n, k) - comb(sz[u], k);
            sz[v] = n;
            sum += dp[v] * sz[v];

            dfs2(v, u);

            sum = psum;
            dp[u] = p1, dp[v] = p2;
            sz[u] = s1, sz[v] = s2;
        }
    };
    dfs2(0, -1);
    cout << ans << '\n';
}