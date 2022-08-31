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
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third;
  bool operator<(const Triple& t) const { if (st != t.st) return st < t.st; if (nd != t.nd) return nd < t.nd; return rd < t.rd; } };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}
typedef Triple<int, int, int> TIII;
template<class A, class B, class C>
ostream& operator<< (ostream &out, Triple<A, B, C> t) { return out << "(" << t.st << ", " << t.nd << ", " << t.rd << ")"; }
template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

const int P = 1e9 + 7;
const int N = 4e5 + 5;
//const int M = 1 << 19;
struct Edge {
  int nei, clam, col;
};
typedef vector<vector<Edge>> VE;

// struct CentDecomp {
//   struct Tree {
//     int M;
//     vector<int> node;
//     Tree(int n = 1) {
//       M = 1;
//       while (M <= n + 2) { M *= 2; }
//       node.resize(2 * M + 5);
//     }
//     int Read(int a) {
//       a = min(a, M - 1) + M;
//       int res = node[a];
//       while (a) {
//         if (a % 2 == 1) { res += node[a - 1]; }
//         a /= 2;
//       }
//       return res;
//     }
//     void Upd(int a, int x) {
//       a += M;
//       while (a) { node[a] += x; a /= 2; }
//     }
//   };
//   /* Start of general part */
//   VE slo;
//   int n;
//   VI sz, dis;
//   struct Info { int cent, dist, subtr; };
//   vector<vector<Info>> cents;
//   vector<Tree> summed;
//   vector<vector<Tree>> branch;
//   vector<int> wei;
//   CentDecomp(VE& slo_, int n_) {
//     slo = slo_;
//     n = n_;
//     summed.resize(n + 2); branch.resize(n + 2); sz.resize(n + 2);
//     dis.resize(n + 2); cents.resize(n + 2); wei.resize(n + 2);
//     Rec(1, n);
//   }
//   void Rec(int v, int size) {
//     v = CntSzCent(v, size, -1, 0, 0);
//     dis[v] = 0;
//     CntSzCent(v, size, -1, v, SZ(slo[v]));
//     for (int i = 0; i < SZ(slo[v]); i++) {
//       int nei = slo[v][i];
//       branch[v].PB(Tree(sz[nei] + 1));
//       DelEdge(nei, v);
//       Rec(nei, sz[nei]);
//     }
//     branch[v].PB(Tree(2));
//     summed[v] = Tree(sz[v]);
//   }
//   int CntSzCent(int v, int size, int par, int root, int subtr) {
//     sz[v] = 1;
//     if (root) { cents[v].PB({root, dis[v], subtr}); }
//     int ret = 0;
//     for (int i = 0; i < SZ(slo[v]); i++) {
//       int nei = slo[v][i];
//       if (v == root) { subtr = i; }
//       if (par == nei) { continue; }
//       dis[nei] = dis[v] + 1;
//       int cnt_rec = CntSzCent(nei, size, v, root, subtr);
//       sz[v] += sz[nei];
//       if (cnt_rec) { ret = cnt_rec; }
//     }
//     if (ret == 0) {
//       if (sz[v] >= size / 2) { return v; } else { return 0; }
//     } else { return ret; }
//   }
//   void DelEdge(int v, int nei) {
//     for (int i = 0; i < SZ(slo[v]); i++) {
//       if (slo[v][i] == nei) {
//         swap(slo[v][i], slo[v].back());
//         slo[v].pop_back();
//         return;
//       }
//     }
//   }
  /* End of general part */
  
//   /* Start of less general part */
//   void Change(int v, int x) {
//     int dif = x - wei[v];
//     wei[v] = x;
//     for (auto tr : cents[v]) {
//       branch[tr.cent][tr.subtr].Upd(tr.dist, dif);
//       summed[tr.cent].Upd(tr.dist, dif);
//     }
//   }
//   int Query(int v, int d) {
//     int res = wei[v];
//     for (auto tr : cents[v]) {
//       int rem_dis = d - tr.dist;
//       if (rem_dis < 0) { continue; }
//       res += summed[tr.cent].Read(rem_dis);
//       res -= branch[tr.cent][tr.subtr].Read(rem_dis);
//     }
//     return res;
//   }
//   /* End of less general part */
//};

VE slo;
int sz[N];
int CntSzCent(int v, int size, int par, int root, int subtr) {
  sz[v] = 1;
  //if (root) { cents[v].PB({root, dis[v], subtr}); }
  int ret = 0;
  for (int i = 0; i < SZ(slo[v]); i++) {
    int nei = slo[v][i].nei;
    if (v == root) { subtr = i; }
    if (par == nei) { continue; }
    //dis[nei] = dis[v] + 1;
    int cnt_rec = CntSzCent(nei, size, v, root, subtr);
    sz[v] += sz[nei];
    if (cnt_rec) { ret = cnt_rec; }
  }
  if (ret == 0) {
    if (sz[v] >= size / 2) { return v; } else { return 0; }
  } else { return ret; }
}

void DelEdge(int v, int nei) {
  for (int i = 0; i < SZ(slo[v]); i++) {
    if (slo[v][i].nei == nei) {
      swap(slo[v][i], slo[v].back());
      slo[v].pop_back();
      return;
    }
  }
}
typedef array<int, 2> A;
void Dfs(int v, vector<pair<A, int>>& ciagnij, int par, pair<A, int> acc) {
  ciagnij.PB(acc);
  for (auto e : slo[v]) {
    int nei = e.nei;
    if (par == nei) { continue; }
    acc.st[e.col]++;
    Dfs(nei, ciagnij, v, {acc.st, acc.nd * e.clam % P});
    acc.st[e.col]--;
  }
}

int spow(int a, int b) {
  int r = 1;
  while (b) {
    if (b % 2) {
      r = r * a % P;
    }
    a = a * a % P;
    b /= 2;
  }
  return r;
}
int Inv(int a) {
  return spow(a, P - 2);
}

int res;
typedef pair<A, int> I;
void UpdateRes(vector<I> ciagniete, int is_mult, int siz) {
  siz = 0;
  for (auto& pp : ciagniete) {
    maxi(siz, pp.st[0]);
    maxi(siz, pp.st[1]);
  }
  cerr<<"ciagniete ";
  for (auto x : ciagniete) {
    cerr<<"(("<<x.st[0]<<", "<<x.st[1]<<"), "<<x.nd<<"), ";
  }
  cerr<<endl;
  debug(is_mult);
  //debug(ciagniete, is_mult);
  int M = 1;
  while (M <= 4 * siz + 5) {
    M *= 2;
  }
  vector<int> drz(2 * M);
  auto Add = [&](int a) {
    a += M;
    while (a) {
      drz[a]++;
      a /= 2;
    }
  };
  auto Read = [&](int a, int b) {
    a += M;
    b += M;
    int sum = drz[a];
    if (a != b) {
      sum += drz[b];
    }
    while (a / 2 != b / 2) {
      if (a % 2 == 0) {
        sum += drz[a + 1];
      }
      if (b % 2 == 1) {
        sum += drz[b - 1];
      }
      a /= 2;
      b /= 2;
    }
    return sum;
  };
  vector<pair<I, int>> evs;
  for (auto p : ciagniete) {
    REP (tr, 2) {
      evs.PB({p, tr});
    }
  }
  auto EvalX = [&](const pair<I, int>& p) {
    if (p.nd == 1) {
      return 2 * (p.st.st.at(0) - 2 * p.st.st.at(1)) - 1;
    } else {
      return 2 * (2 * p.st.st.at(1) - p.st.st.at(0));
    }
  };
  sort(ALL(evs), [&](const pair<I, int>& a, const pair<I, int>& b) { return EvalX(a) < EvalX(b); });
  for (auto p : evs) {
    if (p.nd == 1) {
      Add(p.st.st[1]- 2 * p.st.st[0] + 2 * siz);
    } else {
      int r = Read(0, 2 * p.st.st[0] - p.st.st[1] + 2 * siz);
      if (is_mult == 1) {
        res = res * spow(p.st.nd, r) % P;
      } else {
        res = res * Inv(spow(p.st.nd, r)) % P;
      }
    }
  }
}
void Rec(int v, int size) {
  v = CntSzCent(v, size, -1, 0, 0);
  debug(v);
  //dis[v] = 0;
  //Dfs(v, ciagnij, -1, {{0, 0}, 1});
  CntSzCent(v, size, -1, v, SZ(slo[v]));
  vector<pair<A, int>> ciagniete{{{0, 0}, 1}};
  for (int i = 0; i < SZ(slo[v]); i++) {
    int nei = slo[v][i].nei;
    vector<pair<A, int>> ciagnij;
    pair<A, int> acc;
    acc.st[slo[v][i].col] = 1;
    acc.nd = slo[v][i].clam;
    Dfs(nei, ciagnij, v, acc);
    UpdateRes(ciagnij, -1, size);
    for (auto x : ciagnij) {
      ciagniete.PB(x);
    }
    DelEdge(nei, v);
    Rec(nei, sz[nei]);
  }
  UpdateRes(ciagniete, 1, size);
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  res = 1;
  int n;
  cin>>n;
  slo.resize(n + 5);
  RE (i, n - 1) {
    int u, v, x, c;
    cin>>u>>v>>x>>c;
    slo[u].PB({v, x, c});
    slo[v].PB({u, x, c});
  }
  Rec(1, n);
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}