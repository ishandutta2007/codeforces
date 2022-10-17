#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

const int mod = 998244353;
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
    mint operator -() {return mint(x == 0 ? 0 : mod - x);}
    friend mint operator +(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret += rhs;}
    friend mint operator -(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret -= rhs;}
    friend mint operator *(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret *= rhs;}
    friend mint operator /(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret /= rhs;}
    friend ostream& operator <<(ostream &os, const mint &rhs) {os << rhs.x; return os;}
    friend istream& operator >>(istream &is, mint &rhs) {ll a; is >> a; rhs = a; return is;}
};
mint fpow(mint a,ll b){mint r=1;for(;b;b>>=1){if(b&1)r=r*a;a=a*a;}return r;}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> adj(10), g(10);
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        adj[x] |= 1 << y;
        g[x] |= 1 << y;
        g[y] |= 1 << x;
    }
    vector<mint> dp(1 << 10);
    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        vector<mint> ndp(1 << 10);
        for(int j = 0; j < 1 << 10; ++j) {
            if(dp[j] == 0) continue;
            int mask = 0;
            for(int k = 0; k < 10; ++k) {
                if(j >> k & 1) {
                    mask |= adj[k];
                }
            }
            for(int k = 0; k < 10; ++k) {
                if(mask >> k & 1) continue;
                ndp[(1 << k) | (g[k] & j)] += dp[j];
            }
        }
        dp = ndp;
    }
    mint ans = 0;
    for(mint i : dp) ans += i;
    cout << ans << '\n';
}