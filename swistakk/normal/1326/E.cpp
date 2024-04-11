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
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',') { cerr<<*sdbg++; } cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
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
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

const int N = 1e6 + 5;
int p[N], wh[N], q[N];
const int M = 1 << 19;
struct Node {
  int sum, mi, to_push;
  Node() {
    sum = 0, mi = 0, to_push = 0;
  }
};
Node drz[2 * M + 5];
void Add(int v, int to_add) {
  drz[v].sum += to_add;
  drz[v].mi += to_add;
  drz[v].to_push += to_add;
}
void Touch(int v) {
  assert(v < M);
  FOR (son, 2 * v, 2 * v + 1) {
    Add(son, drz[v].to_push);
  }
  drz[v].to_push = 0;
}
void Add(int bl, int br, int l, int r, int v, int to_add) {
  if (br < l || r < bl) { return; }
  if (l <= bl && br <= r) {
    Add(v, to_add);
    return;
  }
  int m = (bl + br) / 2;
  Touch(v);
  Add(bl, m, l, r, 2 * v, to_add);
  Add(m + 1, br, l, r, 2 * v + 1, to_add);
  drz[v].mi = max(drz[2 * v].mi, drz[2 * v + 1].mi);
}
  
  

// int Read(int a, int b) {
//   a += M - 1;
//   b += M - 1;
//   int r = min(drz[a], drz[b]);
//   while (a / 2 != b / 2) {
//     if (a % 2 == 0) {
//       mini(r, drz[a + 1]);
//     }
//     if (b % 2 == 1) {
//       mini(r, drz[b - 1]);
//     }
//     a /= 2;
//     b /= 2;
//   }
//   return r;
// }
// void Set(int pos, int val) {
//   pos += M - 1;
//   drz[pos] = val;
//   while (pos) {
//     drz[pos] = min(drz[2 * pos], drz[2 * pos + 1]);
//     pos /= 2;
//   }
// }
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  
  int n;
  cin>>n;
  RE (i, n) {
    cin>>p[i];
    wh[p[i]] = i;
  }
//   REP (i, 2 * M + 5) {
//     drz[i] = N;
//   }
  RE (i, n) {
    cin>>q[i];
    //Set(q[i], i);
  }
  // dodaje na prefiksie jak dochodzi nowy element do zgaszenia
  // odejmuje na prefiksie jak dochodzi nowa bomba
  // pytam sie czy istnieje dodatni element
  
  int added_bombs = 0;
  FORD (i, n, 1) {
    Add(1, M, 1, wh[i], 1, 1);
    while (drz[1].mi > 0 && added_bombs < n) {
      cout<<i<<" ";
      added_bombs++;
      Add(1, M, 1, q[added_bombs], 1, -1);
    }
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}