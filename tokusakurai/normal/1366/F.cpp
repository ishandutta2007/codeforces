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

    Mod_Int(ll y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

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

    Mod_Int inverse() const {
        assert(*this != Mod_Int(0));
        return pow(mod-2);
    }

    Mod_Int pow(ll k) const{
        Mod_Int now = *this, ret = 1;
        for(; k; k >>= 1, now *= now){
            if(k&1) ret *= now;
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

template<typename T, bool ismin = true>
struct Convex_Hull_Trick{
    vector<T> a, b; //y = ax+b
    deque<int> que;

    Convex_Hull_Trick() {};

    bool empty() const {return que.empty();}

    T f(int i, const T &x) const {return a[i]*x+b[i];}

    bool judge(int i, int j, int k) const{
        return (b[k]-b[j])*(a[j]-a[i]) >= (b[j]-b[i])*(a[k]-a[j]);
    }

    void add_line(T p, T q){
        if(!ismin) p *= -1, q *= -1;
        assert(empty() || a.back() >= p);
        int k = sz(a);
        a.pb(p), b.pb(q);
        if(!empty() && a[que.back()] == p){
            if(b[que.back()] <= q) return;
            que.pop_back();
        }
        while(sz(que) >= 2 && judge(que[sz(que)-2], que[sz(que)-1], k)) que.pop_back();
        que.push_back(k);
    }

    mint sum(T p, T q, T l, T r){
        mint x = p*(l+r)+2*q, y = r-l+1;
        return x*y;
    }

    mint solve(T R){
        T ptr = 0;
        mint ret = 0;
        while(ptr <= R){
            if(sz(que) == 1){
                int i = que[0];
                ret += sum(a[i], b[i], ptr, R);
                ptr = R+1;
            }
            else{
                int i = que[0], j = que[1];
                que.pop_front();
                if(b[j]-b[i] < 0) continue;
                T r = (b[j]-b[i])/(a[i]-a[j]);
                chmin(r, R);
                if(r < ptr) continue;
                ret += sum(a[i], b[i], ptr, r);
                ptr = r+1;
            }
        }
        return ret/2;
    }

    T query(T x){
        assert(!empty());
        int l = 0, r = sz(que);
        while(r-l > 1){
            int m = (l+r)/2;
            (f(que[m-1], x) >= f(que[m], x)? l : r) = m;
        }
        return ismin? f(que[l], x) : -f(que[l], x);
    }

    T query_monotone_inc(T x){
        assert(!empty());
        while(sz(que) >= 2 && f(que[0], x) >= f(que[1], x)) que.pop_front();
        return ismin? f(que[0], x) : -f(que[0], x);
    }

    T query_monotone_dec(T x){
        assert(!empty());
        while(sz(que) >= 2 && f(que[sz(que)-1], x) >= f(que[sz(que)-2], x)) que.pop_back();
        return ismin? f(que[sz(que)-1], x) : -f(que[sz(que)-1], x);
    }
};

int main(){
    int N, M; ll Q;
    cin >> N >> M >> Q;
    vector<pil> es[N];
    rep(i, M){
        int u, v; ll w;
        cin >> u >> v >> w;
        u--, v--;
        es[u].eb(v, w), es[v].eb(u, w);
    }

    vector<ll> d(N, -INF), m(N, -INF);
    rep(i, N){
        each(e, es[i]) chmax(m[i], e.second);
    }
    vector<vector<ll>> dp(M+1, vector<ll>(N, -INF));
    dp[0][0] = 0;
    rep(i, M){
        rep(j, N){
            each(e, es[j]){
                chmax(dp[i+1][e.first], dp[i][j]+e.second);
            }
        }
    }
    rep(i, N){
        rep(j, M+1){
            chmax(d[i], dp[j][i]+m[i]*(M-j));
        }
    }

    mint ans = 0;
    rep(i, M){
        ans += *max_element(all(dp[i]));
    }

    vector<pll> p;
    rep(i, N){
        if(d[i] != -INF) p.eb(m[i], d[i]);
    }
    sort(all(p));
    Convex_Hull_Trick<ll, false> cht;
    each(e, p) cht.add_line(e.first, e.second);

    ans -= cht.solve(Q-M);
    cout << ans << '\n';
}