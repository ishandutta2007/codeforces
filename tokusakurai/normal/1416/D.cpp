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

    Monoid f(const Monoid &a, const Monoid &b) const {return max(a, b);}
    
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    cin >> N >> M >> Q;
    int a[N];
    rep(i, N) cin >> a[i];
    int u[M], v[M], ord[M];
    fill(ord, ord+M, 0);
    rep(i, M){
        cin >> u[i] >> v[i]; u[i]--, v[i]--;
    }
    int q[Q], x[Q];
    rep(i, Q){
        cin >> q[i] >> x[i]; x[i]--;
        if(q[i] == 2) ord[x[i]] = Q-i;
    }
    vector<int> c(M);
    iota(all(c), 0);
    sort(all(c), [&](int a, int b){
        return ord[a] < ord[b];
    });

    vector<int> root(N), chi[N];
    iota(all(root), 0);
    rep(i, N) chi[i].pb(i);
    int U[M], V[M];
    rep(i, M){
        int j = c[i];
        U[i] = root[u[j]], V[i] = root[v[j]];
        if(U[i] == V[i]) continue;
        if(sz(chi[U[i]]) < sz(chi[V[i]])) swap(U[i], V[i]);
        for(auto &e: chi[V[i]]) root[e] = U[i], chi[U[i]].pb(e);
        chi[V[i]].clear();
    }
    vector<int> comp, rank(N);
    rep(i, N){
        for(auto &e: chi[i]) comp.pb(e);
    }
    rep(i, N) rank[comp[i]] = i;

    pii p[N];
    rep(i, N) p[i] = {rank[i], rank[i]+1};
    vector<pair<int, pii>> change[M];
    rep(i, M){
        if(U[i] == V[i]) continue;
        int s = U[i], t = V[i];
        change[i].eb(s, p[s]), change[i].eb(t, p[t]);
        chmin(p[s].first, p[t].first), chmax(p[s].second, p[t].second);
    }

    vector<pii> b;
    rep(i, N) b.eb(a[comp[i]], i);
    Segment_Tree<pii> seg(b, {-1, -1});

    int ptr = M;
    rep(i, Q){
        if(q[i] == 1){
            int l, r;
            tie(l, r) = p[root[x[i]]];
            pii tmp = seg.query(l, r);
            cout << tmp.first << '\n';
            seg.change(tmp.second, {0, tmp.second});
        }
        else{
            if(change[--ptr].empty()) continue;
            for(auto &e: change[ptr]){
                p[e.first] = e.second;
            }
            auto e = change[ptr].back();
            rep2(j, e.second.first, e.second.second-1){
                root[comp[j]] = e.first;
            }
        }
    }
}