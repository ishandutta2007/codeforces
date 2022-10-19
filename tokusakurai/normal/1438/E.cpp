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

template<typename Monoid>
struct Segment_Tree{
    using F = function<Monoid(Monoid, Monoid)>;
    int n;
    vector<Monoid> seg;
    const F f;
    const Monoid e1;
    
    Segment_Tree(const vector<Monoid> &v, const F &f, const Monoid &e1) : f(f), e1(e1){
        int m = sz(v);
        n = 1;
        while(n < m) n <<= 1;
        seg.assign(2*n, e1);
        copy(all(v), seg.begin()+n);
        for(int i = n-1; i > 0; i--) seg[i] = f(seg[2*i], seg[2*i+1]);
    }
    
    void change(int i, const Monoid &x){
        seg[i += n] = x;
        while(i >>= 1){
            seg[i] = f(seg[2*i], seg[2*i+1]);
        }
    }
 
    Monoid query(int l, int r) const{
        Monoid ret = e1;
        l += n, r += n;
        while(l < r){
            if(l&1) ret = f(ret, seg[l++]);
            if(r&1) ret = f(ret, seg[--r]);
            l >>= 1, r >>= 1;
        }
        return ret;
    }
 
    Monoid operator [] (int i) const {return seg[n+i];}
 
    template<typename C>
    int find_subtree(int i, const C &check, const Monoid &x, Monoid &M, bool type) const{
        while(i < n){
            Monoid nxt = type? f(seg[2*i+type], M) : f(M, seg[2*i+type]);
            if(check(nxt, x)) i = 2*i+type;
            else M = nxt, i = 2*i+(type^1);
        }
        return i-n;
    }
 
    template<typename C>
    int find_first(int l, const C &check, const Monoid &x) const{
        Monoid L = e1;
        int a = l+n, b = n+n;
        while(a < b){
            if(a&1){
                Monoid nxt = f(L, seg[a]);
                if(check(nxt, x)) return find_subtree(a, check, x, L, false);
                L = nxt, a++;
            }
            a >>= 1, b >>= 1;
        }
        return n;
    }
 
    template<typename C>
    int find_last(int r, const C &check, const Monoid &x) const{
        Monoid R = e1;
        int a = n, b = r+n;
        while(a < b){
            if(b&1 || a == 1){
                Monoid nxt = f(seg[--b], R);
                if(check(nxt, x)) return find_subtree(b, check, x, R, true);
                R = nxt;
            }
            a >>= 1, b >>= 1;
        }
        return -1;
    }
};

int main(){
    INT(N);
    VEC(ll, a, N);
    auto f = [](ll x, ll y) {return max(x, y);};
    auto c = [](ll x, ll y) {return x >= y;};
    vll s(N+1, 0);
    rep(i, N) s[i+1] = s[i]+a[i];
    vll v(N);
    rep(i, N) v[i] = a[i]-s[i];
    Segment_Tree<ll> seg(v, f, -INF);
    ll ans = 0;
    rep(i, N){
        int ptr = lower_bound(all(s), a[i]+s[i+1])-begin(s);
        if(ptr == N+1) continue;
        ptr--;
        if(ptr < i+2) ptr = i+2;
        while(ptr < N){
            if((a[i]^a[ptr]) == s[ptr]-s[i+1]) ans++;
            ptr = seg.find_first(ptr+1, c, -a[i]-s[i+1]);
        }
    }
    out(ans);
}