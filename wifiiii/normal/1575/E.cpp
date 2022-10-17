#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

template<typename T>
struct fenwick {
    vector<T> a;
    int n;
    fenwick(int n): n(n), a(n) {}
    void add(int x, T v) {
        assert(0 <= x && x < n);
        for(int i = x + 1; i <= n; i += i & -i) a[i - 1] += v;
    }
    T qry(int x) {
        T ret = 0;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) ret += a[i - 1];
        return ret;
    }
};

const int mod = 1e9 + 7;
//const int mod = 998244353;
ll inv(ll a) {ll u=0,v=1,b=mod;while(a) {ll t=b/a;b-=t*a,u-=t*v;swap(a,b);swap(u,v);}u%=mod;if(u<0)u+=mod;return u;}
struct mint {
    int x;
    mint():x(0) {}
    mint(int x):x(x) {} // 0 <= x < mod
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

#define ll mint

int main() {
    int n, k;
    cin >> n >> k;
    ++k;
    vector<vector<pair<int,int>>> g(n);
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int rt = -1, res = n;
    vector<int> mx(n), sz(n), vis(n);
    function<void(int,int)> dfs = [&](int u, int fa) {
        sz[u] = 1, mx[u] = 0;
        for(auto [v, w] : g[u]) {
            if(v == fa || vis[v]) continue;
            dfs(v, u);
            sz[u] += sz[v];
            mx[u] = max(mx[u], sz[v]);
        }
        mx[u] = max(mx[u], res - sz[u]);
        if(rt == -1 || mx[u] < mx[rt]) rt = u;
    };
    ll ans = 0;
    for(int i = 0; i < n; ++i) ans += a[i];
    function<void(int)> dfs2 = [&](int u) {
        int pre = res;
        vis[u] = 1;
        fenwick<ll> fen(res);
        fenwick<int> fen2(res);
        map<pair<int,int>, ll> mp1;
        map<pair<int,int>, int> mp2;
        function<void(int,int,int,int,int,ll)> dfs3 = [&](int u, int fa, int pre, int cnt, int first, ll sum) {
            // (cnt, sum + a[u])
            if(cnt > k) return;
            sum += a[u];
            mp1[{first, cnt}] += sum;
            mp2[{first, cnt}] += 1;
            fen.add(cnt, sum);
            fen2.add(cnt, 1);
            for(auto [v, w] : g[u]) {
                if(v == fa || vis[v]) continue;
                dfs3(v, u, w, cnt + (w != pre), first, sum);
            }
        };
        function<void(int,int,int,int,int,ll)> dfs4 = [&](int u, int fa, int pre, int cnt, int first, ll sum) {
            // (cnt, sum + a[u])
            if(cnt > k) return;
            sum += a[u];
            ans += fen.qry(k - cnt) + fen2.qry(k - cnt) * sum;
            ll tmp = fen.qry(k - cnt) + fen2.qry(k - cnt) * sum;
            if(mp1.count({first, k + 1 - cnt})) {
                ans += mp1[{first, k + 1 - cnt}] + mp2[{first, k + 1 - cnt}] * sum;
                ll tmp2 = mp1[{first, k + 1 - cnt}] + mp2[{first, k + 1 - cnt}] * sum;
            }
            for(auto [v, w] : g[u]) {
                if(v == fa || vis[v]) continue;
                dfs4(v, u, w, cnt + (w != pre), first, sum);
            }
        };
        fen.add(0, a[u]);
        fen2.add(0, 1);
        for(auto [v, w] : g[u]) {
            if(vis[v]) continue;
            dfs4(v, u, w, 1, w, 0);
            dfs3(v, u, w, 1, w, a[u]);
        }

        for(auto [v, w] : g[u]) {
            if(vis[v]) continue;
            res = sz[v] < sz[u] ? sz[v] : pre - sz[u];
            rt = -1;
            dfs(v, u);
            dfs2(rt);
        }
        res = pre;
    };
    rt = -1; dfs(0, -1);
    dfs2(rt);
    cout << ans << '\n';
}