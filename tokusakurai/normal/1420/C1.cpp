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
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

template<typename Monoid>
struct Segment_Tree{
    vector<Monoid> seg;
    const Monoid e;
    const int n;

    Monoid f(const Monoid &a, const Monoid &b) const {
        //if(a.b == -INF) return b;
        //if(b.b == -INF) return a;
        return{max(a.a+b.a,a.b+b.c), max(a.a+b.b,a.b+b.d), max(a.c+b.a,a.d+b.c), max(a.c+b.b,a.d+b.d)};
    }
    
    Segment_Tree(const vector<Monoid> &v, const Monoid &e)
        : e(e), n(1<<(32-__builtin_clz(sz(v)-1))){
        seg.assign(2*n, e);
        copy(all(v), seg.begin()+n);
        rep3(i, n-1, 1) seg[i] = f(seg[2*i], seg[2*i+1]);
    }
    
    void change(int i, const Monoid &x){
        seg[i += n] = x;
        while(i > 1){
            i >>= 1;
            seg[i] = f(seg[2*i], seg[2*i+1]);
        }
    }

    Monoid query(int a, int b, int i, int l, int r) const{
        if(a >= r || b <= l) return e;
        if(a <= l && r <= b) return seg[i];
        Monoid vl = query(a, b, 2*i, l, (l+r)/2);
        Monoid vr = query(a, b, 2*i+1, (l+r)/2, r);
        return f(vl, vr);
    }

    Monoid query(int a, int b) {return query(a, b, 1, 0, n);}

    bool check(const Monoid &a, const Monoid & b) const {return a <= b;}

    int find_first(int a, int b, const Monoid &x, int i, int l, int r) const{
        if(a >= b || a >= r || b <= l || !check(seg[i], x)) return -1;
        if(r-l == 1) return l;
        int m = (l+r)/2;
        if(b <= m) return find_first(a, b, x, 2*i, l, m);
        if(a >= m) return find_first(a, b, x, 2*i+1, m, r);
        int tmp = find_first(a, m, x, 2*i, l, m);
        return (tmp == -1? find_first(m, b, x, 2*i+1, m, r) : tmp);
    }

    int find_first(int a, int b, const Monoid &x) const {return find_first(a, b, x, 1, 0, n);}

    int find_last(int a, int b, const Monoid &x, int i, int l, int r) const{
        if(a >= b || a >= r || b <= l || !check(seg[i], x)) return -1;
        if(r-l == 1) return l;
        int m = (l+r)/2;
        if(b <= m) return find_last(a, b, x, 2*i, l, m);
        if(a >= m) return find_last(a, b, x, 2*i+1, m, r);
        int tmp = find_last(m, b, x, 2*i+1, m, r);
        return (tmp == -1? find_last(a, m, x, 2*i, l, m) : tmp);
    }

    int find_last(int a, int b, const Monoid &x) const {return find_last(a, b, x, 1, 0, n);}

    Monoid operator [] (int i) const {return seg[n+i];}
};

struct Data{
    ll a, b, c, d;
    Data(ll a, ll b, ll c, ll d) : a(a), b(b), c(c), d(d) {}
};

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, Q;
        cin >> N >> Q;
        vector<Data> v;
        rep(i, N){
            ll x; cin >> x;
            v.eb(0, x, -x, 0);
        }
        Segment_Tree<Data> seg(v, {0, -INF, -INF, 0});
        Data D = seg.query(0, N);
        cout << max({D.a, D.b, D.c, D.b}) << endl;
        while(Q--){
            int l, r; cin >> l >> r; l--, r--;
            swap(v[l], v[r]);
            seg.change(l, v[l]), seg.change(r, v[r]);
            Data D = seg.query(0, N);
            cout << max({D.a, D.b, D.c, D.b}) << endl;
        }
    }
}