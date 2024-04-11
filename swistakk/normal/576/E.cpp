#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
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
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
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

typedef pair<int, bool> PIB;

const int K = 52;
const int M = 1 << 19;
int rep[K][M];

struct RevFU {
  VI sz;
  vector<int> wei;
  int k;
  RevFU(int n, int kk) {
    k = kk;
    //rep.resize(n + 2);
    sz.resize(n + 2);
    wei.resize(n + 2);
    RE (i, n) {
      rep[k][i] = i;
      sz[i] = 1;
    }
  }
  VPII chg;
  int Find(int v) {
    int xorr = 0;
    int dep = 0;
    VI stack;
    while (rep[k][v] != v) {
      xorr = (xorr ^ wei[v]);
      v = rep[k][v];
      dep++;
      stack.PB(v);
    }
//     if (dep > 100) {
//       //debugv(stack);
//       for (auto x : stack) {
//         cerr<<x<<" "<<sz[x]<<endl;
//       }
//       cerr<<SZ(stack)<<endl;
//       assert(false);
//     }
//     assert(dep <= 100);
    return (2 * v ^ xorr);
  }
  void Union(int a, int b) {
    int ap = Find(a);
    int bp = Find(b);
    a = ap / 2;
    b = bp / 2; 
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    chg.PB({a, b});
    if (a == b) { return; }
    sz[a] += sz[b];
    rep[k][b] = a;
    wei[b] = ((ap & 1) ^ (bp & 1) ^ 1);
  }
  void Revert() {
    int a = chg.back().st;
    int b = chg.back().nd;
    chg.pop_back();
    rep[k][b] = b;
    if (a != b) {
      sz[a] -= sz[b];
    }
  }
};

PII edge[M];
int cur_col[M];
struct Query {
  int e_i;
  short c_i, ask;
};
vector<Query> all_queries;
vector<int> tree[2 * M + 5];
vector<RevFU> fu;
void AddToV(int v, int q_num) {
  tree[v].PB(q_num);
}
void AddRec(int v, int a, int b, int bl, int br, int q_num) {
  if (a <= bl && b >= br) {
    //debug(v, a, b, bl, br);
    AddToV(v, q_num);
    return;
  }
  if (a > br || b < bl) { return; }
  int m = (bl + br) / 2;
  AddRec(2 * v, a, b, bl, m, q_num);
  AddRec(2 * v + 1, a, b, m + 1, br, q_num);
}
void AddToTree(int a, int b, int q_num) {
  if (a > b) { return; }
  AddRec(1, a, b, 1, M, q_num); return;
}

int ans[M];
int n;
int nxt[M];
void Traverse(int v, int a, int b) {
  if (v >= 2 * M || a > b) { return; }
  int m = (a + b) / 2;
  VI wh_added;
  while (!tree[v].empty()) {
    auto q_num = tree[v].back();
    auto q = all_queries[q_num];
    tree[v].pop_back();
    int s = edge[q.e_i].st;
    int t = edge[q.e_i].nd;
    if (!q.ask) {
      wh_added.PB(q.c_i);
      fu[q.c_i].Union(s, t);
    } else {
      int col_to_add;
      fu[q.c_i].Union(s, t);
      if (fu[q.c_i].Find(s) == fu[q.c_i].Find(t)) {
        ans[a] = 0;
        col_to_add = cur_col[q.e_i];
        fu[q.c_i].Revert();
      } else {
        ans[a] = 1;
        col_to_add = q.c_i;
        cur_col[q.e_i] = q.c_i;
        wh_added.PB(q.c_i);
      }
      if (col_to_add) {
        all_queries.PB({q.e_i, col_to_add, 0});
        AddToTree(a + 1, nxt[a] - 1, SZ(all_queries) - 1);
      }
    }
  }
  tree[v].shrink_to_fit();
  Traverse(2 * v, a, m);
  Traverse(2 * v + 1, m + 1, b);
  while (!wh_added.empty()) {
    fu[wh_added.back()].Revert();
    wh_added.pop_back();
  }
}
int last[M];
int which_e[M];
int main() {

  //ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  //cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int m, k, q;
  scanf("%d%d%d%d", &n, &m, &k, &q);
  RE (i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    edge[i] = {a, b};
    last[i] = q + 1;
  }
  
  RE (i, k + 1) {
    fu.PB(RevFU(n + 2, i - 1));
  }
  
  RE (i, q) {
    int a, b;
    scanf("%d%d", &a, &b);
    which_e[i] = a;
    all_queries.PB({a, b, 1});
    tree[i + M - 1].PB(SZ(all_queries) - 1);
  }
  FORD (i, q, 1) {
    nxt[i] = last[which_e[i]];
    last[which_e[i]] = i;
  }
  Traverse(1, 1, M);
  RE (i, q) {
    if (ans[i]) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}