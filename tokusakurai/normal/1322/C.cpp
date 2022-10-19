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
#define pq(type, name) priority_queue<type> name
#define iq(type, name) priority_queue<type, vector<type>, greater<type>> name
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y){
    if(x < y) {x = y; return true;}
    return false;
}
template<typename T> bool chmin(T &x, const T &y){
    if(x > y) {x = y; return true;}
    return false;
}
void in() {}
template<typename Head, typename ...Tail> void in(Head &&head, Tail &&...tail){
    cin >> head;
    in(forward<Tail>(tail)...);
}
void out() {cout << '\n';}
template<typename Head, typename ...Tail> void out(Head &&head, Tail &&...tail){
    cout << head << ' ';
    out(forward<Tail>(tail)...);
}
void outn() {}
template<typename Head, typename ...Tail> void outn(Head &&head, Tail &&...tail){
    cout << head << '\n';
    outn(forward<Tail>(tail)...);
}
template<typename T, typename U> void in(pair<T, U> &p){
    cin >> p.first >> p.second;
}
template<typename T, typename U> void out(pair<T, U> p){
    cout << p.first << ' ' << p.second << '\n';
}
using vi = vector<int>;
using vll = vector<ll>;
#define vec1(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC1(type, ...) vector<type>(__VA_ARGS__)
#define vec2(type, name, a, ...) vector<vector<type>> name(a, VEC1(type, __VA_ARGS__))
#define VEC2(type, a, ...) vector<vector<type>>(a, VEC1(type, __VA_ARGS__))
#define vec3(type, name, a, b, ...) vector<vector<vector<type>>> name(a, VEC2(type, b, __VA_ARGS__))
#define VEC3(type, a, b, ...) vector<vector<vector<type>>>(a, VEC2(type, b, __VA_ARGS__))
#define vec4(type, name, a, b, c, ...) vector<vector<vector<vector<type>>>> name(a, VEC3(type, b, c, __VA_ARGS__))
#define VEC4(type, a, b, c, ...) vector<vector<vector<vector<type>>>>(a, VEC3(type, b, c, __VA_ARGS__))
#define vec5(type, name, a, b, c, d, ...) vector<vector<vector<vector<vector<type>>>>> name(a, VEC4(type, b, c, d, __VA_ARGS__))
#define VEC5(type, a, b, c, d, ...) vector<vector<vector<vector<vector<type>>>>>(a, VEC4(type, b, c, d, __VA_ARGS__))
template<typename T> void vin(vector<T> &a){
    rep(i, sz(a)) cin >> a[i];
}
template<typename T> void vout(const vector<T> &a){
    for(auto &e: a) cout << e << ' ';
    cout << '\n';
}
template<typename T> void voutn(const vector<T> &a){
    for(auto &e: a) cout << e << '\n';
}
template<typename T> void unique(vector<T> &a){
    sort(all(a)), a.erase(unique(all(a)), a.end());
}
vector<int> iota(int n){
    vector<int> ret(n);
    iota(all(ret), 0);
    return ret;
}
template<typename T> vector<int> iota(const vector<T> &a, bool greater = false){
    vector<int> ret = iota(sz(a));
    sort(all(ret), [&](int i, int j){
        return (a[i] < a[j])^greater;
    });
    return ret;
}
struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;
#define VEC(type, name, n) vector<type> name(n); vin(name)
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define CHAR(...) char __VA_ARGS__; in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__; in(__VA_ARGS__)
const int MOD = 1000000007;
//const int MOD = 998244353;

struct Random_Number_Generator{
    mt19937_64 mt;

    Random_Number_Generator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

    int64_t operator () (int64_t l, int64_t r){
        uniform_int_distribution<int64_t> dist(l, r-1);
        return dist(mt);
    }

    int64_t operator () (int64_t r){ 
        return (*this)(0, r);
    }
};

using ull = unsigned long long;

struct Rolling_Hash{
    const ull mod = (1ull<<61)-1;

    ull calc_mod(ull x) const{
        ull ret = (x>>61) + x&mod;
        return ret - (ret >= mod? mod : 0);
    }

    ull mul(ull x, ull y) const{
        x = calc_mod(x), y = calc_mod(y);
        ull x1 = x>>31, x2 = x&((1ull<<31)-1), y1 = y>>31, y2 = y&((1ull<<31)-1);
        ull z = x1*y2 + x2*y1, z1 = z>>30, z2 = z&((1ull<<30)-1);
        return calc_mod(x1*y1*2 + x2*y2 + z1 + (z2<<31));
    }

    ull pow(ull x, ull n) const{
        ull ret = 1;
        while(n){
            if(n&1) ret = mul(ret, x);
            x = mul(x, x), n >>= 1;
        }
        return ret;
    }

    ull base;
    vector<ull> hashed, pw;

    void set_base(){
        Random_Number_Generator rnd;
        while(true){
            ull k = rnd(mod);
            if(gcd(mod-1, k) != 1) continue;
            base = pow(3, k);
            if(base < 256) continue;
            break;
        }
    }

    Rolling_Hash(const int &n){
        set_base();
        pw.resize(n+1);
        pw[0] = 1;
        rep(i, n){
            pw[i+1] = mul(pw[i], base);
        }
    }

    ull get_hash(const vector<int> &v) const{
        ull ret = 0;
        each(e, v){
            ret += pw[e];
            if(ret >= mod) ret -= mod;
        }
        return ret;
    }
};

int main(){
    INT(T);
    Rolling_Hash rh(500000);
    while(T--){
        INT(N, M);
        VEC(ll, c, N);
        vi es[N];
        while(M--){
            INT(u, v); u--, v--;
            es[v].eb(u);
        }
        map<ull, vector<int>> mp;
        rep(i, N){
            if(es[i].empty()) continue;
            mp[rh.get_hash(es[i])].eb(i);
        }
        ll ans = 0;
        each(e, mp){
            ll s = 0;
            each(u, e.second) s += c[u];
            ans = gcd(ans, s);
        }
        out(ans);
    }
}