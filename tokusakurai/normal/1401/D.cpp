#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

template<ll mod>
struct Mod_Int{
    ll x;
    Mod_Int() {}
    Mod_Int(ll y) : x (y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    Mod_Int &operator += (const Mod_Int &p){
        x = (x + p.x) % mod;
        return *this;
    }

    Mod_Int &operator -= (const Mod_Int &p){
        x = (x + mod - p.x) % mod;
        return *this;
    }

    Mod_Int &operator *= (const Mod_Int &p){
        x = (x * p.x) % mod;
        return *this;
    }

    Mod_Int &operator /= (const Mod_Int &p){
        *this *= p.inverse();
        return *this;
    }

    Mod_Int &operator ++ () {return *this += Mod_Int(1);}

    Mod_Int operator ++ (int){
        Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Mod_Int &operator -- () {return *this -= Mod_Int(1);}

    Mod_Int operator -- (int){
        Mod_Int tmp = *this;
        --*this;
        return tmp;
    }

    Mod_Int operator - () const {return Mod_Int(-x);}

    Mod_Int operator + (const Mod_Int &p) const {return Mod_Int(*this) += p;}

    Mod_Int operator - (const Mod_Int &p) const {return Mod_Int(*this) -= p;}

    Mod_Int operator * (const Mod_Int &p) const {return Mod_Int(*this) *= p;}

    Mod_Int operator / (const Mod_Int &p) const {return Mod_Int(*this) /= p;}

    bool operator == (const Mod_Int &p) const {return x == p.x;}

    bool operator != (const Mod_Int &p) const {return x != p.x;}

    Mod_Int inverse() const {return pow(mod-2);}

    Mod_Int pow(ll k) const{
        Mod_Int now = *this, ret = 1;
        while(k){
            if(k&1) ret *= now;
            now *= now, k >>= 1;
        }
        return ret;
    }

    friend ostream &operator << (ostream &os, const Mod_Int &p){
        return os << p.x;
    }

    friend istream &operator >> (istream &is, Mod_Int &p){
        ll a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};

using mint = Mod_Int<MOD>;

struct Graph{
    vector<vector<int>> es;
    const int n;
    vector<ll> dp;
    vector<int> par;

    Graph(int n) : n(n){
        es.resize(n), dp.resize(n), par.resize(n);
    }

    void add_edge(int from, int to, bool directed = false){
        es[from].eb(to);
        if(!directed) es[to].eb(from);
    }

    ll dfs(int now, int pre){
        par[now] = pre, dp[now] = 1;
        for(auto &e: es[now]){
            if(e == pre) continue;
            dp[now] += dfs(e, now);
        }
        return dp[now];
    }

    ll query(int u, int v){
        if(par[u] != v) swap(u, v);
        return dp[u]*(n-dp[u]);
    }
};

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        Graph G(N);
        int u[N-1], v[N-1];
        rep(i, N-1){
            cin >> u[i] >> v[i]; u[i]--, v[i]--;
            G.add_edge(u[i], v[i]);
        }
        int M;
        cin >> M;
        ll p[M];
        rep(i, M) cin >> p[i];
        sort(p, p+M, greater<ll>());
        G.dfs(0, -1);
        ll cnt[N-1];
        rep(i, N-1) cnt[i] = G.query(u[i], v[i]);
        sort(cnt, cnt+(N-1), greater<ll>());
        if(N-1 >= M){
            ll ans = 0;
            rep(i, M) ans += cnt[i]*p[i], ans %= MOD;
            rep2(i, M, N-2) ans += cnt[i], ans %= MOD;
            cout << ans << endl;
        }
        else{
            rep2(i, 1, M-N+1) p[0] *= p[i], p[0] %= MOD;
            rep2(i, M-N+2, M-1) p[i-(M-N+1)] = p[i];
            ll ans = 0;
            rep(i, N-1) ans += cnt[i]*p[i], ans %= MOD;
            cout << ans << endl;
        }
    }
}