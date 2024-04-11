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

template<typename Monoid, typename Operator_Monoid>
struct Lazy_Segment_Tree{
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, Operator_Monoid)>;
    using H = function<Operator_Monoid(Operator_Monoid, Operator_Monoid)>;
    int n, height;
    vector<Monoid> seg;
    vector<Operator_Monoid> lazy;
    const F f;
    const G g;
    const H h;
    const Monoid e1;
    const Operator_Monoid e2;
    
    Lazy_Segment_Tree(const vector<Monoid> &v, const F &f, const G &g, const H &h, const Monoid &e1, const Operator_Monoid &e2)
        : f(f), g(g), h(h), e1(e1), e2(e2){
        int m = sz(v);
        n = 1, height = 0;
        while(n < m) n <<= 1, height++;
        seg.assign(2*n, e1), lazy.assign(2*n, e2);
        copy(all(v), seg.begin()+n);
        for(int i = n-1; i > 0; i--) seg[i] = f(seg[2*i], seg[2*i+1]);
    }

    inline Monoid reflect(int i) const{
        return (lazy[i] == e2? seg[i] : g(seg[i], lazy[i]));
    }

    inline void recalc(int i){
        while(i >>= 1) seg[i] = f(reflect(2*i), reflect(2*i+1));
    }

    inline void eval(int i){
        if(i < n && lazy[i] != e2){
            lazy[2*i] = h(lazy[2*i] ,lazy[i]);
            lazy[2*i+1] = h(lazy[2*i+1], lazy[i]);
            seg[i] = reflect(i), lazy[i] = e2;
        }
    }

    inline void thrust(int i){
        for(int j = height; j > 0; j--) eval(i>>j);
    }
    
    void apply(int l, int r, const Operator_Monoid &x){
        chmax(l, 0), chmin(r, n);
        if(l >= r) return;
        l += n, r += n;
        thrust(l), thrust(r-1);
        int a = l, b = r;
        while(l < r){
            if(l&1) lazy[l] = h(lazy[l], x), l++;
            if(r&1) r--, lazy[r] = h(lazy[r], x); 
            l >>= 1, r >>= 1;
        }
        recalc(a), recalc(b-1);
    }
    
    Monoid query(int l, int r){
        chmax(l, 0), chmin(r, n);
        if(l >= r) return e1;
        l += n, r += n;
        thrust(l), thrust(r-1);
        Monoid L = e1, R = e1;
        while(l < r){
            if(l&1) L = f(L, reflect(l++));
            if(r&1) R = f(reflect(--r), R);
            l >>= 1, r >>= 1;
        }
        return f(L, R);
    }

    Monoid operator [] (int i) {return query(i, i+1);}

    template<typename C>
    int find_subtree(int i, const C &check, const Monoid &x, Monoid &M, bool type){
        while(i < n){
            eval(i);
            Monoid nxt = type? f(reflect(2*i+type), M) : f(M, reflect(2*i+type));
            if(check(nxt, x)) i = 2*i+type;
            else M = nxt, i = 2*i+(type^1);
        }
        return i-n;
    }
 
    template<typename C>
    int find_first(int l, const C &check, const Monoid &x){
        Monoid L = e1;
        int a = l+n, b = n+n;
        thrust(a);
        while(a < b){
            if(a&1){
                Monoid nxt = f(L, reflect(a));
                if(check(nxt, x)) return find_subtree(a, check, x, L, false);
                L = nxt, a++;
            }
            a >>= 1, b >>= 1;
        }
        return n;
    }
 
    template<typename C>
    int find_last(int r, const C &check, const Monoid &x){
        Monoid R = e1;
        int a = n, b = r+n;
        thrust(b-1);
        while(a < b){
            if(b&1 || a == 1){
                Monoid nxt = f(reflect(--b), R);
                if(check(nxt, x)) return find_subtree(b, check, x, R, true);
                R = nxt;
            }
            a >>= 1, b >>= 1;
        }
        return -1;
    }
};

int main(){
    int N; cin >> N;

    vector<int> a(N), b;
    rep(i, N) {cin >> a[i]; a[i]--;}

    for(int i = 0; i < N;){
        int j = 0;
        while(i+j < N && a[i] == a[i+j]) j++;
        b.eb(a[i]), i += j;
    }

    auto f = [](ll a, ll b) {return min(a, b);};
    auto g = [](ll a, ll b) {return a+b;};

    vector<ll> v(N+1, inf);

    int n = sz(b);
    v[N] = 1;
    Lazy_Segment_Tree<ll, ll> seg(v, f, g, g, INF, 0);

    rep2(i, 1, n-1){
        ll tmp = seg.query(0, N+1)+1;
        chmin(tmp, seg[b[i]]);

        seg.apply(0, N+1, 1);
        ll pre = seg.query(b[i-1], b[i-1]+1);
        if(tmp < pre) seg.apply(b[i-1], b[i-1]+1, tmp-pre);
    }

    cout << seg.query(0, N+1) << '\n';
}