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

const int N = 4e3 + 5;
int side[N];

int vis[N];
vector<PII> slo[N];
void AddEdge(int a, int b, int c) {
  slo[a].PB({b, c});
  slo[b].PB({a, c});
  debug(a, b, c);
}
void Dfs(int v) {
  vis[v] = 1;
  for (auto e : slo[v]) {
    int nei = e.st;
    if (vis[nei]) {
      if (side[v] != (side[nei] ^ e.nd)) {
        puts("-1");
        exit(0);
      }
      continue;
    }
    side[nei] = side[v] ^ e.nd;
    debug(nei, side[nei], v, side[v]);
    Dfs(nei);
  }
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  vector<string> b1(n), b2(n);
  REP (i, n) {
    cin>>b1[i];
  }
  REP (i, n) {
    cin>>b2[i];
  }
  VVI cel(n, VI(n));
  REP (i, n) {
    REP (j, n) {
      if (b1[i][j] == b2[i][j]) {
        cel[i][j] = 0;
      } else {
        cel[i][j] = 1;
      }
    }
  }
  string s;
  cin>>s;
  // r - 1..n, c-n+1..2n
  // 0 - 2n+1
  REP (i, n) {
    REP (j, n) {
      if (s[i] == '0' && s[j] == '0') {
        if (cel[i][j]) {
          puts("-1");
          return 0;
        }
      } else if (s[i] == '0' && s[j] == '1') {
        AddEdge(i + 1, 2 * n + 1, cel[i][j]);
      } else if (s[i] == '1' && s[j] == '0') {
        AddEdge(j + n + 1, 2 * n + 1, cel[i][j]);
      } else {
        AddEdge(i + 1, j + n + 1, cel[i][j]);
      }
    }
  }
  FORD (i, 2 * n + 1, 1) {
    if (vis[i]) { continue; }
    Dfs(i);
  }
  int m = 0;
  RE (i, n) {
    m += side[i];
    m += side[i + n];
  }
  cout<<m<<endl;
  RE (i, n) {
    if (side[i]) {
      cout<<"row "<<i - 1<<"\n";
    }
  }
  RE (i, n) {
    if (side[i + n]) {
      cout<<"col "<<i - 1<<"\n";
    }
  }
//   if (s == string(n, '0')) {
//     if (cel == VVI(n, VI(n))) {
//       puts("0");
//     } else {
//       puts("-1");
//     }
//     return 0;
//   }
//   if (s == 
//   REP (tr, 2) {
//     VVI cur(n, VI(n));
//     vector<pair<string, int>> ruchy;
//     if (tr) {
//       cur = s;
//       ruchy.PB({"row", 0});
//     }
//     REP (j, n) {
//       if (cur[0][j]) {
//         ruchy.PB("col", j});
//         REP (i, n) {
//           if (s[i] == '1') {
//             cur[i][j] ^= 1;
//           }
//         }

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}