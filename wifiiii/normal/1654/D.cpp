#include<bits/stdc++.h>
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


const int N = 2e5 + 5;
int cnt[N], cnt2[N];
int prime[N], np[N], mp[N], tot = 0;

void init(int n) {
    np[1] = 1;
    for(int i = 2; i <= n; ++i) {
        if(!np[i]) prime[++tot] = i, mp[i] = i;
        for(int j = 1; j <= tot; ++j) {
            if(i * prime[j] > n) break;
            np[i * prime[j]] = 1;
            mp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
}

vector<pair<int,int>> d[N];
int main() {
    init(N - 1);
    for(int i = 2; i < N; ++i) {
        int x = i;
        while(x != 1) {
            int c = 0, p = mp[x];
            while(x % p == 0) {
                ++c;
                x /= p;
            }
            d[i].push_back({p, c});
        }
    }
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<array<int, 3>>> g(n);
        vector<int> vis;
        for(int i = 1; i < n; ++i) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            --u, --v;
            g[u].push_back({v, x, y});
            g[v].push_back({u, y, x});
            for(auto [p, c] : d[x]) {
                vis.push_back(p);
            }
            for(auto [p, c] : d[y]) {
                vis.push_back(p);
            }
        }
        sort(vis.begin(), vis.end());
        vis.resize(unique(vis.begin(), vis.end()) - vis.begin());
        for(int p : vis) cnt[p] = cnt2[p] = 0;
        function<void(int, int)> dfs = [&](int u, int fa) {
            for(auto [v, x, y] : g[u]) {
                if(v == fa) continue;
                for(auto [p, c] : d[y]) {
                    cnt[p] += c;
                }
                for(auto [p, c] : d[x]) {
                    cnt[p] -= c;
                    cnt2[p] = min(cnt2[p], cnt[p]);
                }
                dfs(v, u);
                for(auto [p, c] : d[y]) {
                    cnt[p] -= c;
                }
                for(auto [p, c] : d[x]) {
                    cnt[p] += c;
                }
            }
        };
        dfs(0, -1);
        mint cur = 1, sum = 0;
        for(int p : vis) {
            cur *= fpow(p, cnt[p] - cnt2[p]);
        }
        function<void(int, int)> dfs2 = [&](int u, int fa) {
            sum += cur;
            for(auto [v, x, y] : g[u]) {
                if(v == fa) continue;
                cur = cur * y / x;
                dfs2(v, u);
                cur = cur * x / y;
            }
        };
        dfs2(0, -1);
        cout << sum << '\n';
    }
}