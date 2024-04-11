#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

template<int mod>
struct Mod_Int{
    int x;

    Mod_Int() : x(0) {}

    Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    Mod_Int &operator += (const Mod_Int &p){
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator -= (const Mod_Int &p){
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator *= (const Mod_Int &p){
        x = (int) (1LL * x * p.x % mod);
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

    Mod_Int inverse() const{
        assert(*this != Mod_Int(0));
        return pow(mod-2);
    }

    Mod_Int pow(long long k) const{
        Mod_Int now = *this, ret = 1;
        for(; k > 0; k >>= 1, now *= now){
            if(k&1) ret *= now;
        }
        return ret;
    }

    friend ostream &operator << (ostream &os, const Mod_Int &p){
        return os << p.x;
    }

    friend istream &operator >> (istream &is, Mod_Int &p){
        long long a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};

using mint = Mod_Int<MOD>;

template<int mod>
struct Combination{
    using T = Mod_Int<mod>;
    vector<T> _fac, _ifac;

    Combination(int n){
        _fac.resize(n+1), _ifac.resize(n+1);
        _fac[0] = 1;
        for(int i = 1; i <= n; i++) _fac[i] = _fac[i-1]*i;
        _ifac[n] = _fac[n].inverse();
        for(int i = n; i >= 1; i--) _ifac[i-1] = _ifac[i]*i;
    }

    T fac(int k) const {return _fac[k];}

    T ifac(int k) const {return _ifac[k];}

    T comb(int n, int k) const{
        if(k < 0 || n < k) return 0;
        return fac(n)*ifac(n-k)*ifac(k);
    }

    T comb2(int x, int y) const {return comb(x+y, x);}

    T perm(int n, int k) const{
        if(k < 0 || n < k) return 0;
        return fac(n)*ifac(n-k);
    }

    T second_stirling_number(int n, int k) const{ //nk1
        T ret = 0;
        for(int i = 0; i <= k; i++){
            T tmp = comb(k, i)*T(i).pow(n);
            ret += ((k-i)&1)? -tmp : tmp;
        }
        return ret*ifac(k);
    }

    T bell_number(int n, int k) const{ //nk
        if(n == 0) return 1;
        k = min(k, n);
        vector<T> pref(k+1);
        pref[0] = 1;
        for(int i = 1; i <= k; i++){
            if(i&1) pref[i] = pref[i-1]-ifac(i);
            else pref[i] = pref[i-1]+ifac(i);   
        }
        T ret = 0;
        for(int i = 1; i <= k; i++){
            ret += T(i).pow(n)*ifac(i)*pref[k-i];
        }
        return ret;
    }
};

using comb = Combination<MOD>;

comb C(1000);

mint dp[201][201], idp[201][201];
mint pw[401];

template<bool directed = false>
struct Graph{
    struct edge{
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    vector<vector<int>> par; //par[i][j] := j2^i
    vector<int> depth;
    const int height;

    Graph(int n) : es(n), n(n), m(0), depth(n), height(32-__builtin_clz(n)){
        par.assign(height, vector<int>(n));
    }

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++;
    }

    void prepare(int now, int pre = -1){
        if(pre == -1) depth[now] = 0;
        par[0][now] = pre;
        for(auto &e: es[now]){
            if(e.to != pre){
                depth[e.to] = depth[now]+1;
                prepare(e.to, now);
            }
        }
    }

    void build(int root = 0){ //root
        prepare(root);
        for(int j = 0; j < height-1; j++){
            for(int i = 0; i < n; i++){
                if(par[j][i] == -1) par[j+1][i] = -1;
                else par[j+1][i] = par[j][par[j][i]];
            }
        }
    }

    int lca(int u, int v){
        if(depth[u] < depth[v]) swap(u, v);
        int D = depth[u]-depth[v];
        for(int i = 0; i < height; i++){
            if((D>>i)&1) u = par[i][u];
        }
        if(u == v) return u;
        for(int i = height-1; i >= 0; i--){
            if(par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
        }
        return par[0][u];
    }

    int dist(int u, int v){
        return depth[u]+depth[v]-2*depth[lca(u, v)];
    }

    mint solve(){
        mint ret = 0;
        rep(j, n){
            rep(i, j){
                int u = lca(i, j);
                int a = depth[i]-depth[u], b = depth[j]-depth[u];
                if(a == 0) continue;
                if(b == 0) {ret++; continue;}
                ret += dp[b][a-1]*idp[a][b];
            }
        }
        return ret;
    }
};

int main(){
    int N; cin >> N;

    mint tw = mint(2).inverse();
    pw[0] = 1;
    rep(i, 400) pw[i+1] = pw[i]*tw;

    rep(a, 201){
        dp[a][0] = pw[a];
        rep2(b, 1, 200){
            dp[a][b] = dp[a][b-1]+C.comb(a+b-1, b)*pw[a+b];
        }
    }
    rep2(i, 1, 200){
        rep2(j, 1, 200){
            idp[i][j] = (dp[j][i-1]+dp[i][j-1]).inverse();
        }
    }

    Graph G(N);

    rep(i, N-1){
        int u, v; cin >> u >> v; u--, v--;
        G.add_edge(u, v);
    }

    mint ans = 0;

    rep(i, N){
        G.build(i);
        ans += G.solve();
    }

    cout << ans/N << '\n';
}