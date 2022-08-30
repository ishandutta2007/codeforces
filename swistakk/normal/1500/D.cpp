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

const int N = 1502;
int last[N * N];
int col[N][N];
int id;
int q;
// void ShiftSelf(VPII& r) {
//   for (auto& p : r) {
//     r.st++;
//   }
// }
VPII Shift(VPII r) {
  for (auto& p : r) {
    p.st++;
  }
  return r;
}
VPII Merge(VPII r1, VPII r2) { // (gdzie, kolor)
  id++;
  VPII res;
  res.reserve(11);
  int f1 = 0, f2 = 0;
  while (f1 < SZ(r1) || f2 < SZ(r2)) {
    int who = 0;
    if (f1 == SZ(r1) || (f2 < SZ(r2) && r2[f2].st < r1[f1].st)) {
      who = 1;
    }
    PII p;
    if (who == 0) {
      p = r1[f1];
    } else {
      p = r2[f2];
    }
    if (last[p.nd] != id) {
      last[p.nd] = id;
      res.PB(p);
      if (SZ(res) == q + 1) {
        return res;
      }
    }
    if (who == 0) {
      f1++;
    } else {
      f2++;
    }
  }
  return res;
}
VPII hor[N][N];
VPII ver[N][N];
//VPII single[N][N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n>>q;
  VPII start;
  RE (i, n) {
    RE (j, n) {
      cin>>col[i][j];
      if (i == n || j == n) {
        start.PB({i, j});
      }
      //single[i][j] = {{0, col[i][j]}};
    }
  }
  sort(ALL(start), [&](PII A, PII B) { return A.st - A.nd < B.st - B.nd; }); 
  FORD (i, n, 1) {
    FORD (j, n, 1) {
      //hor[i][j] = hor[i + 1][j];
      //ver[i][j] = ver[i][j + 1];
      //ShiftSelf(hor[i][j]);
      //ShiftSelf(ver[i][j]);
      
      //hor[i][j].reserve(11);
      ver[i][j].reserve(11);
      //hor[i][j] = Merge(Shift(hor[i][j + 1]), VPII{{0, col[i][j]}});
      ver[i][j] = Merge(Shift(ver[i + 1][j]), VPII{{0, col[i][j]}});
    }
  }
  VI cnt_wrong(n + 2);
  int lol = 0;
  for (auto p : start) {
    int i = p.st;
    int j = p.nd;
    int side = 1;
    VPII r;
    while (i >= 1 && j >= 1) {
      hor[i][j].reserve(11);
      hor[i][j] = Merge(Shift(hor[i][j + 1]), VPII{{0, col[i][j]}});
      r = Merge(Merge(Merge(VPII{{0, col[i][j]}}, Shift(r)), Shift(ver[i + 1][j])), Shift(hor[i][j + 1]));
      hor[i][j + 1].clear();
      hor[i][j + 1].shrink_to_fit();
      int bad = -1;
      if (SZ(r) <= q) {
        bad = side + 1;
      } else {
        bad = min(r[q].st, side) + 1;
      }
      debug(i, j, r, bad);
      cnt_wrong[bad]++;
      side++;
      lol++;
      i--;
      j--;
    }
  }
  assert(lol == n * n);
  RE (i, n) {
    lol -= cnt_wrong[i]; 
    cout<<lol<<"\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}