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

const int M = 1e6 + 5;
int drz[M][3];
int Magic(int n) {
  return n - (n & (n - 1));
}
void Add(int ind, int val, int tr) {
  while (ind < M) {
    drz[ind][tr] += val;
    ind += Magic(ind);
  }
}

int Read(int ind, int tr) {
  int res = 0;
  while (ind) {
    res += drz[ind][tr];
    ind -= Magic(ind);
  }
  return res;
}
set<int> poses[3];
int cur_shape[M];

int n;
int Count(int L, int R, int tr) {
  return Read(R, tr) - Read(L - 1, tr);
}
int Licz() {
  if (n == 1) { return 1; }
  vector<VI> intvs(3);
  int nonempty = 0;
  REP (tr, 3) {
    if (poses[tr].empty()) {
      intvs[tr] = {-1, -1};
    } else {
      intvs[tr].PB(*poses[tr].begin());
      intvs[tr].PB(*(prev(poses[tr].end())));
      nonempty++;
    }
  }
  if (nonempty == 1) { return n; }
  if (nonempty == 2) {
    REP (tr, 3) {
      if (intvs[tr][0] != -1 && intvs[(tr + 1) % 3][0] != -1) {
        return SZ(poses[tr]);
      }
    }
  }
  int res = n;
  REP (tr, 3) {
    int IWinWith = (tr + 1) % 3;
    int ILoseWith = (tr + 2) % 3;
    int L1 = intvs[ILoseWith][0];
    int R1 = intvs[IWinWith][0];
    int L2 = intvs[IWinWith][1];
    int R2 = intvs[ILoseWith][1];
    if (L1 > R1) {
      L1 = -1;
      R1 = -1;
    }
    if (L2 > R2) {
      L2 = -1;
      R2 = -1;
    }
    if (L1 == -1 && L2 == -1) { continue; }
    if (L1 == -1) {
      res -= Count(L2, R2, tr);
      continue;
    }
    if (L2 == -1) {
      res -= Count(L1, R1, tr);
      continue;
    }
    if (R1 >= L2) {
      res -= Count(min(L1, L2), max(R1, R2), tr);
    } else {
      res -= Count(L2, R2, tr);
      res -= Count(L1, R1, tr);
    }
  }
//   VVI where_ans(3);
//   int beg = cur_shape[1];
//   where_ans[beg].PB(1);
//   where_ans[(beg + 2) % 3].PB(1);
//   where_ans[(beg + 1) % 3].PB(intvs[(beg + 2) % 3][0]);
//   int en = cur_shape[n];
//   where_ans[en].PB(n);
//   where_ans[(en + 2) % 3].PB(n);
//   where_ans[(en + 1) % 3].PB(intvs[(en + 2) % 3][1]);
//   int res = 0;
//   REP (tr, 3) {
//     if (where_ans[tr][0] > where_ans[tr][1]) { continue; }
//     res += Read(where_ans[tr][1], tr);
//     res -=  Read(where_ans[tr][0] - 1, tr);
//   }
  return res;
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int q;
  cin>>n>>q;
  map<char, int> mapuj;
  mapuj['R'] = 0;
  mapuj['S'] = 1;
  mapuj['P'] = 2;
  
  RE (i, n) {
    char c;
    cin>>c;
    int fav = mapuj[c];
    cur_shape[i] = fav;
    poses[fav].insert(i);
    Add(i, 1, fav);
  }
  cout<<Licz()<<"\n";
  RE (i, q) {
    int who, fav;
    cin>>who;
    char c;
    cin>>c;
    int prv_shape = cur_shape[who];
    fav = mapuj[c];
    poses[prv_shape].erase(who);
    poses[fav].insert(who);
    Add(who, -1, prv_shape);
    Add(who, 1, fav);
    cur_shape[who] = fav;
    cout<<Licz()<<"\n";
  }
    
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}