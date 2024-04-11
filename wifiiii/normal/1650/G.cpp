#include<bits/stdc++.h>
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
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        int s, t;
        cin >> s >> t;
        --s, --t;
        vector<vector<int>> g(n);
        for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        auto solve = [&](int s) {
            vector<int> dis(n, -1);
            vector<mint> dp(n);
            dis[s] = 0, dp[s] = 1;
            queue<int> q;
            q.push(s);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int v : g[u]) {
                    if(dis[v] == -1) {
                        dis[v] = dis[u] + 1;
                        q.push(v);
                    }
                    if(dis[v] == dis[u] + 1) {
                        dp[v] += dp[u];
                    }
                }
            }
            return make_pair(dis, dp);
        };
        auto [dis1, dp1] = solve(s);
        auto [dis2, dp2] = solve(t);
        mint ans = dp1[t];
        for(int i = 0; i < n; ++i) {
            if(dis1[i] + dis2[i] == dis1[t]) {
                for(int u : g[i]) {
                    if(dis2[u] == dis2[i]) {
                        ans += dp1[i] * dp2[u];
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}