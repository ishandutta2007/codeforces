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
template<typename T> void in(T &x){
    cin >> x;
}
template<typename T> void out(T x){
    cout << x << '\n';
}
template<typename T> void out2(T x){
    cout << x << ' ';
}
template<typename T, typename U> void in(pair<T, U> &p){
    cin >> p.first >> p.second;
}
template<typename T, typename U> void out(pair<T, U> p){
    cout << p.first << ' ' << p.second << '\n';
}
using vi = vector<int>;
using vll = vector<ll>;
#define vec(type, name, a, x) vector<type> name(a, x)
#define VEC(type, a, x) vector<type>(a, x)
#define vec2(type, name, a, b, x) vector<vector<type>> name(a, VEC(type, b, x))
#define VEC2(type, a, b, x) vector<vector<type>>(a, VEC(type, b, x))
#define vec3(type, name, a, b, c, x) vector<vector<vector<type>>> name(a, VEC2(type, b, c, x))
#define VEC3(type, a, b, c, x) vector<vector<vector<type>>>(a, VEC2(type, b, c, x))
#define vec4(type, name, a, b, c, d, x) vector<vector<vector<vector<type>>>> name(a, VEC3(type, b, c, d, x))
#define VEC4(type, a, b, c, d, x) vector<vector<vector<vector<type>>>>(a, VEC3(type, b, c, d, x))
#define vec5(type, name, a, b, c, d, e, x) vector<vector<vector<vector<vector<type>>>>> name(a, VEC4(type, b, c, d, e, x))
#define VEC5(type, a, b, c, d, e, x) vector<vector<vector<vector<vector<type>>>>>(a, VEC4(type, b, c, d, e, x))
template<typename T> void in(vector<T> &a){
    rep(i, sz(a)) cin >> a[i];
}
template<typename T> void out(const vector<T> &a){
    for(auto &e: a) cout << e << '\n';
}
template<typename T> void out2(const vector<T> &a){
    for(auto &e: a) cout << e << ' ';
    cout << '\n';
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
const int MOD = 1000000007;
//const int MOD = 998244353;

int main(){
    int T; in(T);
    while(T--){
        ll a, b, c, d; in(a), in(b), in(c), in(d);
        if(a > b*c) {out(-1); continue;}
        ll x = a/b, y = x/d;
        //out2(y);
        out((y+1)*a-y*(y+1)*d*b/2);
    }
}