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

void solve(int a, int b){
    if(a == 0 && b == 0) out("BN");
    else out(string(a, 'B')+string(b, 'N'));
}

int main(){
    INT(N);
    VEC(string, S, N);
    int l = -1, r = inf; //(l, r]
    vi x(N, 0), y(N, 0);
    int mc = inf, Mc = -inf;
    int mx = inf, Mx = -inf, my = inf, My = -inf;
    rep(i, N){
        each(e, S[i]) (e == 'B'? x : y)[i]++;
        chmin(mc, x[i]-y[i]), chmax(Mc, x[i]-y[i]);
        chmin(mx, x[i]), chmax(Mx, x[i]), chmin(my, y[i]), chmax(My, y[i]);
    }
    while(r-l > 1){
        int m = (l+r)/2;
        int lc = Mc-m, rc = mc+m;
        int lx = Mx-m, rx = mx+m, ly = My-m, ry = my+m;
        if(lx > rx || ly > ry || lc > rc) {l = m; continue;}
        int a = lx-ry, b = rx-ly;
        if(rc <  a || lc > b) l = m;
        else r = m;
    }
    out(r);
    int lc = Mc-r, rc = mc+r;
    int lx = Mx-r, rx = mx+r, ly = My-r, ry = my+r;
    int a = lx-ry, b = rx-ly;
    if(a >= lc) solve(lx, ry);
    else if(b <= rc) solve(rx, ly);
    else{
        int d = lc-a;
        if(d <= ry-ly) solve(lx, ry-d);
        else solve(lx+d-(ry-ly), ly); 
    }
}