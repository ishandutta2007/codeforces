#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;


int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n)) x++;
  return x;
}

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
             lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
               log = ceil_pow2(_n);
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



struct S {
  ll active_sum = 0;
  ll active_cnt = 0;
  ll active_ok = 1;
  ll passive_sum = 0;
  ll passive_cnt = 0;
  ll passive_ok = 1;
  ll cnt = 0;
};

S op(S a, S b) {
  S res;
  res.active_sum = a.active_sum + b.active_sum;
  res.active_cnt = a.active_cnt + b.active_cnt;
  res.active_ok = (a.active_ok && b.active_ok);
  res.passive_sum = a.passive_sum + b.passive_sum;
  res.passive_cnt = a.passive_cnt + b.passive_cnt;
  res.passive_ok = (a.passive_ok && b.passive_ok);
  res.cnt = a.cnt + b.cnt;
  return res;
}
S e() { return S{0,0,1,0,0,1,0}; }

using F = int;
F id() { return 0; }
F composition(F f, F g) { return f^g; }
S mapping(F f, S s) {
  if(f) {
    swap(s.active_sum, s.passive_sum);
    swap(s.active_cnt, s.passive_cnt);
    swap(s.active_ok, s.passive_ok);
  }
  return s;
}

using tree = lazy_segtree<S,op,e,F,mapping,composition,id>;


template <bool VALS_EDGES> struct HLD {
  int N, tim = 0;
  vector<vi> adj;
  vi par, siz, depth, rt, pos;
  HLD(vector<vi> adj_)
    : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
    rt(N),pos(N){ dfsSz(0); dfsHld(0); }
  void dfsSz(int v) {
    if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
    for (int& u : adj[v]) {
      par[u] = v, depth[u] = depth[v] + 1;
      dfsSz(u);
      siz[v] += siz[u];
      if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
    }
  }
  void dfsHld(int v) {
    pos[v] = tim++;
    for (int u : adj[v]) {
      rt[u] = (u == adj[v][0] ? rt[v] : u);
      dfsHld(u);
    }
  }
  template <class B> void process(int u, int v, B op) {
    for (; rt[u] != rt[v]; v = par[rt[v]]) {
      if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
      op(pos[rt[v]], pos[v] + 1);
    }
    if (depth[u] > depth[v]) swap(u, v);
    op(pos[u] + VALS_EDGES, pos[v] + 1);
  }
  void processSubtree(int v, auto& op) { // modifySubtree is similar
    op(pos[v]+VALS_EDGES, pos[v]+siz[v]);
  }
};

int main() {
  //cin.tie(0)->sync_with_stdio(0);
  //cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  map<pii,int> ed_to_id;
  vector<vi> g(n);
  rep(i,1,n) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
    ed_to_id[{x,y}] = ed_to_id[{y,x}] = i;
  }

  tree st(n);
  HLD<0> hld(g);

  int active_cnt = 0;
  vi active(n);

  auto mark_ok = [&](int x) {
    if(!active[x] || hld.par[x] == -1 || !active[hld.par[x]]) return;
    auto s = st.get(hld.pos[x]);
    s.active_ok = s.passive_ok = true;
    st.set(hld.pos[x],s);
  };

  auto activate = [&](int x) {
    debug("activate", x);
    active[x] = 1;
    ++active_cnt;

    int below = st.prod(hld.pos[x], hld.pos[x]+hld.siz[x]).cnt;
    debug(below);

    auto s = st.get(hld.pos[x]);
    if(below%2 == 1) { // intentionally wrong, since flip below
      s.active_ok = false;
      s.active_sum = ed_to_id[{x,hld.par[x]}];
      s.active_cnt = 1;
    }
    else {
      s.passive_ok = false;
      s.passive_sum = ed_to_id[{x,hld.par[x]}];
      s.passive_cnt = 1;
    }
    s.cnt = 1;
    st.set(hld.pos[x],s);

    mark_ok(x);
    for(int y : hld.adj[x]) mark_ok(y);

    hld.process(0,x, [&](int l, int r){
        st.apply(l,r,1);
    });

    //rep(i,0,n) debug(i,st.get(i)); // TODO comment out!
  };

  auto query = [&]() -> ll {
    auto s = st.all_prod();
    if(!s.active_ok) return 0;
    if(2*s.active_cnt != active_cnt) return 0;
    return s.active_sum;
  };

  auto enumerate = [&]() {
    if(query() == 0) {
      cout << 0 << endl;
      return;
    }
    vi v;
    rep(i,0,n) {
      auto s = st.get(i);
      if(s.active_sum) v.emplace_back(s.active_sum);
    }
    sort(all(v));
    cout << sz(v);
    for(int x : v) cout << " " << x;
    cout << endl;
  };

  activate(0);

  while(true) {
    int t;
    cin>>t;
    if(t == 1) {
      int x;
      cin>>x;
      --x;
      activate(x);
      cout << query() << endl;
    }
    else if(t == 2) {
      enumerate();
    }
    else if(t == 3) exit(0);
    else assert(false);
  }
}