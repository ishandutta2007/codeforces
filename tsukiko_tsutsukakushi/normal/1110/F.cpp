/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
typedef pair<int, ll> P;
typedef pair<int, pair<int, int>> P2;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T, typename S>
struct LazySegmentTree{
private:
    int n;
    vector<T> node;
    vector<S> lazy;
    T E0;
    S E1;

    inline void updatef(S& lazy,S& value){
        lazy += value;
        //lazy = max(lazy, value);
        //lazy = min(lazy, value);
    }
    inline void calculatef(T& node,S& lazy,int len){
        // node += lazy * len; //sum
        node += lazy ; //max
    }
    inline T queryf(T& x,T& y){
        //return x + y;
        //return x * y;
        //return max(x, y);
        return min(x, y);
    }
public:
    LazySegmentTree(int sz,T nodeE,S lazyE ):E0(nodeE), E1(lazyE){
        n=1;
        while(n<sz)n<<=1;
        node.resize(2*n-1,E0);
        lazy.resize(2*n-1,E1);
    }

    LazySegmentTree(vector<T>& v,T E0,S E1 ):E0(E0),E1(E1){
        n=1;
        int sz=v.size();
        while(n<sz)n<<=1;
        node.resize(2*n-1,E0);
        lazy.resize(2*n-1,E1);
        rep(i,sz)node[i+n-1] = v[i];
        for(int i=n-2; i>=0; --i){
            node[i] = queryf(node[2*i+1],node[2*i+2]);
        }
    }

    void eval(int k,int l,int r){
        if(lazy[k]==E1)return ;
        calculatef(node[k], lazy[k], r-l);
        if(r-l>1){
            updatef(lazy[2*k+1], lazy[k]);
            updatef(lazy[2*k+2], lazy[k]);
        }
        lazy[k]=E1;
    }

    void update(int a, int b, S x,int k=0,int l=0,int r=-1){
        if(r<0)r=n;
        eval(k,l,r);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            updatef(lazy[k], x);
            eval(k,l,r);
        }
        else {
            update(a,b,x,2*k+1,l,(l+r)/2);
            update(a,b,x,2*k+2,(l+r)/2,r);
            node[k]=queryf(node[2*k+1], node[2*k+2]);
        }
    }

    T query(int a,int b,int k=0,int l=0,int r=-1){
        if(r<0)r=n;
        eval(k,l,r);
        if(r<=a||b<=l)return E0;
        if(a<=l&&r<=b)return node[k];
        T xl=query(a,b,2*k+1,l,(l+r)/2);
        T xr=query(a,b,2*k+2,(l+r)/2,r);
        return queryf(xl, xr);
    }
    void debug() {
        // for(int i = n - 1; i < 2 * n - 1; ++ i) {
        //     cerr << node[i] << " \n"[i == 2 * n - 2];
        // }
        rep(i, n) {
            cerr << query(i, i + 1) << " \n"[i == n - 1];
        }
    }
};

const ll INF = 1LL<<60;

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<P>> g(n, vector<P>());
    vector<ll> dist(n, INF);
    // dist[0] = 0;
    for(int i = 1; i < n; ++ i) {
        int p; ll w; cin >> p >> w;
        -- p;
        // dist[i] = dist[p] + w;
        g[i].push_back({p, w});
        g[p].push_back({i, w});
    }
    vector<vector<int>> t(n, vector<int>(2));
    int id = 0;
    auto dfs = [&](auto&& self, int v, int p, ll d) -> void {
        if(g[v].size() == 1 and g[v][0].fr == p) {
            // leaf
            dist[v] = d;
        }
        t[v][0] = id ++;
        for(auto e: g[v]) {
            int nv = e.fr;
            if(nv == p) continue;
            self(self, nv, v, d + e.sc);
        }
        t[v][1] = id;
        return;
    };
    dfs(dfs, 0, -1, 0);
    vector<int> ans(q, INF);
    vector<vector<int>> h(n);
    vector<int> l(q), r(q);
    rep(i, q) {
        int v; cin >> v >> l[i] >> r[i];
        -- v, -- l[i];
        h[v].push_back(i);
    }
    LazySegmentTree<ll, ll> seg(dist, INF, 0);
    auto dfs2 = [&](auto&& self, int v, int p) -> void {
        for(int i: h[v]) {
            // cerr << i << "\n";
            // seg.debug();
            ans[i] = seg.query(l[i], r[i]);
        }
        for(auto e: g[v]) {
            int nv = e.fr;
            ll w = e.sc;
            if(nv == p) continue;
            seg.update(0, n, w);
            seg.update(t[nv][0], t[nv][1], -2LL * w);
            self(self, nv, v);
            seg.update(0, n, -w);
            seg.update(t[nv][0], t[nv][1], 2LL * w);
        }
        return;
    };
    dfs2(dfs2, 0, -1);
    rep(i, q) {
        cout << ans[i] << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}