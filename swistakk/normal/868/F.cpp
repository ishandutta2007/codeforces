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

const int kInf = 1e18;
const int N = 1e5 + 5;
const int K = 22;
int dp[N][K];
vector<int> ruchy;
int cur_cost;
int arr[N];
int occ[N];
// void cof(){
//   int ak = ruchy.back();
//   ruchy.pop_back();
//   cur_cost -= occ[a[ak]] - 1;
//   occ[a[ak]]--;
// }
int added[N];
void sub(int i) {
  debug("-",i);
  assert(added[i]);
  added[i] = 0;
  occ[arr[i]]--;
  cur_cost -= occ[arr[i]];
}
void add(int i) {
  debug("+",i);
  assert(!added[i]);
  added[i] = 1;
  cur_cost += occ[arr[i]];
  occ[arr[i]]++;
}
// void licz(int p,int k,int po,int ko){
//   if(p+1 == k){
//     wyn[p] = po;
//     return;
//   }
//   int me = (p+k)/2;
//   F(i,me,k)add(i);
//   int y = po;
//   while(add(y))y++;
//   cof();cof();
//   F(i,po,y)cof(),cof();
//   licz(p,me,po,y);
//   F(i,me,k)cof(),cof();
//   F(i,po,y)add(i);
//   licz(me,k,y,ko);
//   F(i,po,y)cof(),cof();
// }
void Rec(int a, int b, int l, int r, int lvl) { // active [l, a)
  if (a > b) { return; }
  debug(a, b, l, r, lvl);
  int m = (a + b) / 2;
  
  FOR (i, a, m) { // [l, m]
    add(i);
  }
  int best = cur_cost + dp[l - 1][lvl - 1];
  int wh = l;
  int last = min(m - 1, r - 1);
  FOR (i, l, last) { // [last + 1, m]
    sub(i);
    int cand = cur_cost + dp[i][lvl - 1];
    if (cand < best) {
      best = cand;
      wh = i + 1;
    }
  }
  dp[m][lvl] = best;
  debug(best, wh);
  FORD (i, last, wh) { // [wh, m]
    add(i);
  }
  Rec(m + 1, b, wh, r, lvl);
  FORD (i, wh - 1, l) { // [l, m]
    add(i);
  }
  FORD (i, m, a) { // [l, a)
    sub(i);
  }
  Rec(a, m - 1, l, wh, lvl);
}
  

    
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, k;
  cin>>n>>k;
  RE (i, n) {
    cin>>arr[i];
  }
  REP (i, N) {
    REP (j, K) {
      dp[i][j] = kInf;
    }
  }
  dp[0][0] = 0;
  RE (i, k) {
    Rec(1, n, 1, n, i);
  }
  cout<<dp[n][k]<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}