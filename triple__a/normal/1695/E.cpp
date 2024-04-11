// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
// #include <bits/extc++.h>
#define int long long
// #define double long double
// #define i128 long long
// #define double long double
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal
template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n((int)(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};


int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
const int mod=1e9+7;
const double EPS=1e-9;
// const double pi=acos(-1);
const int INF=1e18;
const int N=600007;
mt19937 rng(1235);
int modpow(int u,int v){
    int ans=1, t=u;
    while (v){
        if (v&1) ans=ans*t%mod;
        t=t*t%mod, v>>=1;
    }
    return ans;
}

using S=pii;
using F=int;

S op(S l,S r){return make_pair(min(l.F,r.F),max(l.S,r.S));}
S e(){return {INF,-INF};}
S mapping(F l,S r){return r;}
F composition(F l,F r){return l+r;}
F id(){return 0;}

struct Eulerian{
  public:
    Eulerian(int n,int m):_n(n),_m(m){
        path.clear();
        _g.resize(n,vector<pii>(0));
        pt.resize(n,0);
        vis.resize(m,0);
        deg.resize(n,0);    
    }
    void add(int x,int y,int id){
        _g[x].pb({y,id});
        pt[x]++;
        nxt=x;
        deg[y]++;
    }
    bool solve(){
        rep(i,_n) if (deg[i]&1) return false;
        dfs(nxt);
        if (sz(path)<_m) return 0;
        return true;
    }
    vi solve_path(){
        if (!solve()) path.clear();
        reverse(range(path));
        return path;
    }
  private:
    int _n,_m,nxt;
    vi path;
    vector<vector<pii>> _g;
    vi pt;
    vi deg;
    vector<bool> vis;
    int abs(int u){
        if (u<0) return ~u;
        return u;
    }
    void dfs(int u){
        while (pt[u]){
            while (pt[u]&&vis[abs(_g[u][pt[u]-1].S)]) pt[u]--;
            if (!pt[u]) break;
            int to=_g[u][pt[u]-1].F, id=_g[u][pt[u]-1].S;
            vis[abs(id)]=1;
            dfs(to), path.pb(id);
        }
    }
};
int n,m;
int par[N],x[N],y[N],sz[N];
int ans[2][N],ans1[2][N], ans2[2][N];
vi edges[N], comp[N];
vector<pii> g[N];
bool vis[N],vis2[N];
int fnd(int u){
    if (par[u]==u) return u;
    return par[u]=fnd(par[u]);
}
void unite(int u,int v){
    int pu=fnd(u), pv=fnd(v);
    if (pu==pv) return;
    par[pu]=pv, sz[pv]+=sz[pu];
}

void dfs(int u,int p,vi& path){
    path.pb(u);
    if (vis[u]) return;
    vis[u]=1;
    for (auto c:g[u]){
        if (vis2[c.S]) continue;
        vis2[c.S]=1;
        dfs(c.F,u,path);
        path.pb(u);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.precision(15);
    cin>>n;
    rep1(i,2*n) par[i]=i; 
    rep(i,n) {
        cin>>x[i]>>y[i];
        if (x[i]<y[i]) swap(x[i],y[i]);
        sz[x[i]]++, sz[y[i]]++, g[x[i]].pb({y[i],i}), g[y[i]].pb({x[i],i});
    }
    rep(i,n) unite(x[i],y[i]);
    rep1(i,2*n) comp[fnd(i)].pb(i);
    vector<vi> paths;
    rep1(i,2*n){
        if (fnd(i)!=i) continue;
        if (sz[i]==2) {cout<<"-1\n"; return 0;}
        if (!sz[i]) continue;
        vi path;
        dfs(comp[i][0],-1,path);
        path.pop_back();
        // assert(sz(path)==sz[i]*2);
        paths.pb(path);
    }
    cout<<2<<" "<<n<<"\n";
    int nowcol=0;
    for (auto v:paths){
        int m=sz(v)/2;
        rep(i,2*m){
            if (i<m) ans[0][i+nowcol]=v[i];
            else ans[1][2*m-i-1+nowcol]=v[i];
        }
        if (m&1){
            rep(i,m-1){
                if ((i&1)^1) ans1[0][i+nowcol]=ans1[1][i+nowcol]=ans2[0][i+1+nowcol]=ans2[1][i+1+nowcol]=0;
                else ans1[0][i+nowcol]=ans1[1][i+nowcol]=ans2[0][i+1+nowcol]=ans2[1][i+1+nowcol]=1;
            }
            ans1[0][nowcol+m-1]=ans2[0][nowcol]=2;
            ans1[1][nowcol+m-1]=ans2[1][nowcol]=3;
        }
        else{
            ans1[0][nowcol+m-1]=ans1[0][nowcol]=2;
            ans1[1][nowcol+m-1]=ans1[1][nowcol]=3;
            rep(i,m-2){
                if ((i&1)^1) ans1[0][i+1+nowcol]=ans1[1][i+1+nowcol]=0;
                else ans1[0][i+1+nowcol]=ans1[1][i+1+nowcol]=1;
            }
            rep(i,m){
                if ((i&1)^1) ans2[0][i+nowcol]=ans2[1][i+nowcol]=0;
                else ans2[0][i+nowcol]=ans2[1][i+nowcol]=1;
            }
        }
        nowcol+=m;
    }
    rep(i,2) {
        rep(j,n) cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
    auto t=[&](int u){
        if (u==0) return 'L';
        if (u==1) return 'R';
        if (u==2) return 'U';
        return 'D';
    };
    rep(i,2){
        rep(j,n) cout<<t(ans1[i][j]);
        cout<<"\n";
    }
    rep(i,2){
        rep(j,n) cout<<t(ans2[i][j]);
        cout<<"\n";
    }
    return 0;
}
/*
4
10 1
1 7
5 10
7 5
*/