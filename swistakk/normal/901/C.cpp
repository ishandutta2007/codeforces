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
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
const int N = 5e5 + 5;
const int M = 1 << 19;
int drz1[2 * M + 5];
int drz2[2 * M + 5];
int vis[N];
void Upd(int a, int v) {
  a += M;
  drz1[a] = v;
  drz2[a] = v;
  a /= 2;
  while (a) {
    drz1[a] = min(drz1[2 * a], drz1[2 * a + 1]);
    drz2[a] = max(drz2[2 * a], drz2[2 * a + 1]);
    a /= 2;
  }
}
PII Read(int a, int b) {
  a += M;
  b += M;
  int mi = min(drz1[a], drz1[b]);
  int ma = max(drz2[a], drz2[b]);
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      mini(mi, drz1[a + 1]);
      maxi(ma, drz2[a + 1]);
    }
    if (b % 2 == 1) {
      mini(mi, drz1[b - 1]);
      maxi(ma, drz2[b - 1]);
    }
    a /= 2;
    b /= 2;
  }
  return {mi, ma};
}
VI slo[N];
int pos[N];
VI stos;
VPII ps;
// struct Ev {
//   int l, r, typ;
//   bool operator<(const Ev& oth) {
//     if (l != oth.l) { return l > oth.l; }
//     return typ < oth.yup;
// }
// vector<Ev> evs;
int res[N];
int cand_beg[N];
void Dfs(int v, int par) {
  vis[v] = 1;
  stos.PB(v);
  pos[v] = SZ(stos);
  Upd(pos[v], v);
  for (auto nei : slo[v]) {
    if (nei == par) { continue; }
    if (vis[nei] && pos[nei] < pos[v]) {
      auto p = Read(pos[nei], pos[v]);
      mini(cand_beg[p.st], p.nd);
      //evs.PB({p.st, p.nd, 0});
      //ps.PB(Read(pos[nei], pos[v]));
    }
    if (vis[nei]) { continue; }
    Dfs(nei, v);
  }
  stos.pop_back();
}
int drz[2 * M + 5];
int to_push[2 * M + 5];
void Touch(int v) {
  //debug(v);
  REP (tr, 2) {
    drz[2 * v + tr] += to_push[v];
    to_push[2 * v + tr] += to_push[v] / 2;
  }
  to_push[v] = 0;
}
void AddSum(int l, int r, int bl, int br, int v, int wid) {
  if (br < l || bl > r) { return; }
  if (l <= bl && br <= r) {
    drz[v] += wid;
    to_push[v] += wid / 2;
    return;
  }
  int m = (bl + br) / 2;
  //debug(l, r, bl, br, v, wid);
  Touch(v);
  AddSum(l, r, bl, m, 2 * v, wid / 2);
  AddSum(l, r, m + 1, br, 2 * v + 1, wid / 2);
  drz[v] = drz[2 * v] + drz[2 * v + 1];
}
int ReadSum(int l, int r, int bl, int br, int v) {
  if (br < l || bl > r) { return 0; }
  if (l <= bl && br <= r) {
    return drz[v];
  }
  int m = (bl + br) / 2;
  Touch(v);
  return ReadSum(l, r, bl, m, 2 * v) + ReadSum(l, r, m + 1, br, 2 * v + 1);
}
// int Magic(int n) {
//   return n - (n & (n - 1));
// }
// void AddSum(int a) {
//   while (a < N) {
//     pot[a] += 1;
//     a += Magic(a);
//   }
// }
// int ReadSum(int a) {
//   int r = 0;
//   while (a) {
//     r += pot[a];
//     a -= Magic(a);
//   }
//   return r;
// }
VPII qs[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  RE (i, n) {
    cand_beg[i] = n + 1;
  }
  RE (i, m) {
    int a, b;
    cin>>a>>b;
    slo[a].PB(b);
    slo[b].PB(a);
  }
  RE (i, n) {
    if (vis[i] == 0) { Dfs(i, -1); }
  }
  debug(ps);
  int q_cnt;
  cin>>q_cnt;
  RE (i, q_cnt) {
    int l, r;
    cin>>l>>r;
    qs[l].PB({r, i});
    //evs.PB({l, r, i});
  }
  //sort(ALL(evs));
  int beg = n + 1;
  FORD (i, n, 1) {
    mini(beg, cand_beg[i]);
    debug(i, beg);
    AddSum(beg, n + 1, 1, M, 1, M);
    for (auto q : qs[i]) {
      int r = q.st;
      int len = r - i + 1;
      int sum = ReadSum(1, r, 1, M, 1);
      debug(q.nd, sum);
      int ans = len * (len + 1) / 2 - sum;
      res[q.nd] = ans;
    }
  }
  RE (i, q_cnt) {
    cout<<res[i]<<"\n";
  }
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}