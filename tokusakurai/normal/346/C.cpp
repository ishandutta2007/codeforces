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

template<typename T, typename Operator_Monoid>
struct Dual_Segment_Tree{
    using G = function<T(T, Operator_Monoid)>;
    using H = function<Operator_Monoid(Operator_Monoid, Operator_Monoid)>;
    int n, height;
    vector<T> seg;
    vector<Operator_Monoid> lazy;
    const G g;
    const H h;
    const Operator_Monoid e2;

    Dual_Segment_Tree(const vector<T> &v, const G &g, const H &h, const Operator_Monoid &e2) : g(g), h(h), e2(e2){
        int m = v.size();
        n = 1, height = 0;
        while(n < m) n <<= 1, height++;
        lazy.assign(2*n, e2);
        seg = v;
    }

    inline void eval(int i){
        if(i < n && lazy[i] != e2){
            lazy[2*i] = h(lazy[2*i], lazy[i]);
            lazy[2*i+1] = h(lazy[2*i+1], lazy[i]);
            lazy[i] = e2;
        }
    }

    inline void thrust(int i){
        for(int j = height; j > 0; j--) eval(i>>j);
    }

    void apply(int l, int r, const Operator_Monoid &x){
        l = max(l, 0), r = min(r, n);
        if(l >= r) return;
        l += n, r += n;
        thrust(l), thrust(r-1);
        while(l < r){
            if(l&1) lazy[l] = h(lazy[l], x), l++;
            if(r&1) r--, lazy[r] = h(lazy[r], x);
            l >>= 1, r >>= 1;
        }
    }

    T get(int i){
        thrust(i+n);
        return g(seg[i], lazy[i+n]);
    }

    T operator [] (int i) {return get(i);}
};

int main(){
    int N; cin >> N;

    vector<ll> x(N);
    rep(i, N) cin >> x[i];

    sort(all(x));
    x.erase(unique(all(x)), end(x));

    ll a, b; cin >> b >> a;
    N = b-a+1;
    vector<ll> d(N, 0);

    each(e, x){
        for(ll i = e*((a+e-1)/e); i <= b; i += e){
            chmax(d[i-a], e);
        }
    }

    auto g = [](int a, int b) {return min(a, b);};
    auto h = [](int a, int b) {return min(a, b);};
    vector<int> v(N, inf);
    v[0] = 0;
    Dual_Segment_Tree<int, int> seg(v, g, h, inf);

    rep(i, N-1){
        int x = seg[i];
        if(d[i] > 0) seg.apply(i+1, min<int>(N, i+d[i]), x+1);
        seg.apply(i+1, i+2, x+1);
    }

    cout << seg[N-1] << '\n';
}