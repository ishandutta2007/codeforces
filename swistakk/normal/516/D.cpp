#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#ifdef LOCAL
#define debug(x) {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, t) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#t <<" = " <<t<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x,y,z,t)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
using namespace std;
typedef long long LL;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third; };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}



struct FastrigateTree {
  
  FastrigateTree(vector<vector<LL>>& slo, int n_, int root = 1, vector<LL> v_wei = vector<LL>()) {
    vector<vector<pair<LL, LL>>> new_slo;
    for (auto& v : slo) {
      new_slo.PB(vector<pair<LL, LL>>());
      for (auto x : v) {
        new_slo.back().PB(MP(x, 1));
      }
    }
    Init(new_slo, n_, root, v_wei);
  }
  
  FastrigateTree (vector<vector<pair<LL, LL>> >& slo, int n_, int root = 1, vector<LL> v_wei = vector<LL>()) {
    Init(slo, n_, root, v_wei);
  }
  
  LL n, sum_wei;
  vector<LL> pre_only; // preorder only from [1..n]
  vector<LL> pre, post; // preorder and postorder togehter from [1..2n]
  vector<LL> sum_dis_down; // sum of distances to vertices in subtree
  vector<LL> sum_dis; // sum of distances to all vertices in tree
  vector<LL> dis_longest_down, where_longest_down; // length of longest path going down and its end
  vector<LL> depth;
  vector<LL> dis_longest_up, where_longest_up; // length of longest path going firstly up and its end
  vector<LL> dis_longest_down_excl, where_longest_down_excl; // longest_down_excl[v] = length of the longest path going down from par[v] but not through v and its end
  vector<LL> dis_longest_all, where_longest_all;
  vector<LL> par; // parent
  vector<LL> sz; // sz[v] - size of subtree
  int d_pre_only;
  int d_pre_post;
  vector<int> centroids;
  LL diam1 = 1, diam2 = 1, diam_len = 0;
  LL diam_mid1 = 1, diam_mid2 = 1, diam_dev_from1 = 0; 
  
private:
  
  void Init(vector<vector<pair<LL, LL>>>& slo, int n_, int root, vector<LL>& v_wei) {
    n = n_;
    pre_only.resize(n + 2);
    pre.resize(n + 2);
    post.resize(n + 2);
    sum_dis_down.resize(n + 2);
    sum_dis.resize(n + 2);
    dis_longest_down.resize(n + 2);
    where_longest_down.resize(n + 2);
    depth.resize(n + 2);
    dis_longest_up.resize(n + 2);
    dis_longest_down_excl.resize(n + 2);
    where_longest_up.resize(n + 2);
    where_longest_down_excl.resize(n + 2);
    dis_longest_all.resize(n + 2);
    where_longest_all.resize(n + 2);
    par.resize(n + 2);
    sz.resize(n + 2);
    if (SZ(v_wei) == 0) {
      v_wei = vector<LL>(n + 2, 1);
    }
    sum_wei = 0;
    for (int i = 1; i <= n; i++) {
      sum_wei += v_wei[i];
    }
    d_pre_only = d_pre_post = 0;
    Dfs1(slo, root, 0, v_wei);
    sum_dis[root] = sum_dis_down[root];
    where_longest_up[root] = root;
    Dfs2(slo, root, 0);
    diam1 = where_longest_all[1];
    diam2 = where_longest_all[diam1];
    diam_len = dis_longest_all[diam1];
//     RE (i, n) {
//       cerr<<where_longest_down[i]<<" ";
//     }
//     cerr<<"\n";
//     RE (i, n) {
//       cerr<<where_longest_down_excl[i]<<" ";
//     }
//     cerr<<"\n";
//     RE (i, n) {
//       cerr<<dis_longest_down_excl[i]<<" ";
//     }
//     cerr<<"\n";
//     RE (i, n) {
//       cerr<<where_longest_up[i]<<" ";
//     }
//     cerr<<"\n";
//     RE (i, n) {
//       cerr<<dis_longest_up[i]<<" ";
//     }
//     cerr<<"\n";
//     RE (i, n) {
//       cerr<<where_longest_all[i]<<" ";
//     }
//     cerr<<"\n";
    debug2(diam1, diam2);
    debug2(dis_longest_all[diam1], dis_longest_all[diam2]);
    assert(diam_len == dis_longest_all[diam2]);
    for (int v = 1; v <= n; v++) {
      for (auto p : slo[v]) {
        int nei = p.first;
        if (nei == par[v]) { continue; }
        if (where_longest_all[v] != where_longest_all[nei]) {
          diam_mid1 = v;
          diam_mid2 = nei;
          diam_dev_from1 = dis_longest_all[v] - diam_len / 2 ;
        }
      }
    }
  }
  
  

  void Dfs1(vector<vector<pair<LL, LL>>>& slo, int v, int parent, vector<LL>& v_wei) {
    sz[v] = v_wei[v];
    d_pre_only++;
    pre_only[v] = d_pre_only;
    d_pre_post++;
    pre[v] = d_pre_post;
    par[v] = parent;
    where_longest_down[v] = v;
    LL where_sec_longest = 0;
    LL dis_sec_longest = -1;
    LL can_centroid = 1;
    for (auto p : slo[v]) {
      LL nei = p.first;
      LL c = p.second;
      if (nei == parent) { continue; }
      depth[nei] = depth[v] + c;
      Dfs1(slo, nei, v, v_wei);
      if (sz[nei] > sum_wei / 2) {
        can_centroid = 0;
      }
      sz[v] += sz[nei];
      sum_dis_down[v] += sum_dis_down[nei] + sz[nei] * c;
      LL cand_dis = dis_longest_down[nei] + c;
      LL cand_where = where_longest_down[nei];
      if (cand_dis > dis_longest_down[v]) {
        where_sec_longest = where_longest_down[v];
        dis_sec_longest = dis_longest_down[v];
        where_longest_down[v] = cand_where;
        dis_longest_down[v] = cand_dis;
      } else if (cand_dis > dis_sec_longest) {
        where_sec_longest = cand_where;
        dis_sec_longest = cand_dis;
      }
    }
    debug3(v, where_longest_down[v], where_sec_longest);
    if (where_sec_longest == v) {
      where_sec_longest = 0;
    }
    for (auto p : slo[v]) {
      LL nei = p.first;
      if (nei == par[v]) { continue; }
      if (where_longest_down[nei] != where_longest_down[v]) {
        where_longest_down_excl[nei] = where_longest_down[v];
        dis_longest_down_excl[nei] = dis_longest_down[v];
      } else {
        where_longest_down_excl[nei] = where_sec_longest;
        dis_longest_down_excl[nei] = dis_sec_longest;
      }
    }   
    if (sum_wei - sz[v] <= sum_wei / 2 && can_centroid) {
      centroids.PB(v);
    }
    d_pre_post++;
    post[v] = d_pre_post;
  }
      
  void Dfs2(vector<vector<pair<LL, LL>>>& slo, int v, LL e_par_cost) {
    if (dis_longest_down_excl[v] > dis_longest_up[par[v]]) {
      dis_longest_up[v] = e_par_cost + dis_longest_down_excl[v];
      where_longest_up[v] = where_longest_down_excl[v];
    } else {
      cerr<<"tu\n";
      dis_longest_up[v] = e_par_cost + dis_longest_up[par[v]];
      where_longest_up[v] = where_longest_up[par[v]];
      if (where_longest_up[v] == 0) {
        where_longest_up[v] = v;
      }
    }
    for (auto p : slo[v]) {
      LL nei = p.first;
      LL c = p.second;
      if (par[v] == nei) { continue; }
      sum_dis[nei] = sum_dis[v] + c * (sum_wei - 2 * sz[nei]);
      Dfs2(slo, nei, c);
    }
    if (dis_longest_up[v] > dis_longest_down[v]) {
      dis_longest_all[v] = dis_longest_up[v];
      where_longest_all[v] = where_longest_up[v];
    } else {
      dis_longest_all[v] = dis_longest_down[v];
      where_longest_all[v] = where_longest_down[v];
    }
  }
};
    

void AddEdge(int a, int b, int c, vector<vector<pair<LL, LL>>>& s) {
  s[a].PB(MP(b, c));
  s[b].PB(MP(a, c));
}
const int N = 1e5 + 5;
vector<vector<pair<int, int>>> slo;
int q;
int l[N];
vector<int> mids;
int cand[N];
int dep[N];
const int Q = 55;
int to_subtract[N][Q];
void Dfs1(int v, VI& stack) {
  stack.PB(v);
  RE (i, q) {
    int kl = 0, kp = SZ(stack) - 1, faj = -1;
    while (kl <= kp) {
      int aktc = (kl + kp) / 2;
      if (dep[stack[aktc]] < dep[v] - l[i]) {
        kl = aktc + 1;
        faj = aktc;
      } else {
        kp = aktc - 1;
      }
    }
    if (faj >= 0) {
      to_subtract[stack[faj]][i]++;
    }
  }
  for (auto p : slo[v]) {
    int nei = p.st;
    int dis = p.nd;
    if (nei == mids[0] || nei == mids[1]) { continue; }
    if (dep[nei]) { continue; }
    dep[nei] = dep[v] + dis;
    Dfs1(nei, stack);
  }
  stack.pop_back();
}
int sz[N];
void Dfs2(int v, int ii) {
  sz[v]++;
  for (auto p : slo[v]) {
    int nei = p.st;
    if (nei == mids[0] || nei == mids[1]) { continue; }
    if (dep[nei] < dep[v]) { continue; }
    Dfs2(nei, ii);
    sz[v] += sz[nei];
  }
  sz[v] -= to_subtract[v][ii];
  maxi(cand[ii], sz[v]);
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  slo.resize(n + 5);
  RE (i, n - 1) {
    make3(int, x, y, v);
    AddEdge(x, y, v, slo);
  }
  vector<LL> v_wei(n + 2, 1);
  debug("a");
  FastrigateTree fast(slo, n, 1, v_wei);
  debug("b");
  int d1 = fast.diam_mid1;
  int d2 = fast.diam_mid2;
  int minfar = min(fast.dis_longest_all[d1], fast.dis_longest_all[d2]);
  vector<int> alldis;
  RE (i, n) {
    alldis.PB(fast.dis_longest_all[i]);
  }
  sort(ALL(alldis));
  debugv(alldis);
  cin>>q;
  RE (i, q) {
    cin>>l[i];
    while (cand[i] < n && alldis[cand[i]] <= minfar + l[i]) {
      cand[i]++;
    }
    cerr<<cand[i]<<" ";
  }
  cerr<<"\n";
  mids.PB(d1);
  mids.PB(d2);
  
  debugv(mids);
  RE (i, n) {
    cerr<<fast.dis_longest_all[i]<<" ";
  }
  cerr<<"\n";
  REP (tr, 2) {
    VI stack = VI();;
    dep[mids[tr]] = 1;
    Dfs1(mids[tr], stack);
  }
  
  RE (i, q) {
    RE (j, n) {
      sz[j] = 0;
    }
    REP (tr, 2) {
      Dfs2(mids[tr], i);
    }
    cout<<cand[i]<<"\n";
  }
  
  RE (qq, q) {
    RE (i, n) {
      cerr<<to_subtract[i][qq]<<" ";
    }
    cerr<<"\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}