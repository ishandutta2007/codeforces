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

const int N = 1e6 + 5;
int p[N], vis[N];
//~ bool dp[N];
int pref[N];
bitset<N> dp;
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, k;
  cin>>n>>k;
  RE (i, n) {
    cin>>p[i];
  }
  VI cycs;
  map<int, int> cnt_lens;
  RE (i, n) {
    if (vis[i]) { continue; }
    int cnt = 0;
    int cur = p[i];
    while (cur != i) {
      cnt++;
      vis[cur] = 1;
      cur = p[cur];
    }
    cnt_lens[cnt + 1]++;
    cycs.PB(cnt + 1);
  }
  debug(cycs);
  int odd = 0;
  int min_to_all = 0;
  for (auto c : cycs) {
    min_to_all += (c + 1) / 2;
    odd += c % 2;
  }
  int M = 0;
  if (min_to_all <= k) {
    M = n;
  } else {
    int take_odds = min(odd, min_to_all - k);
    int cand = n;
    cand -= take_odds;
    min_to_all -= take_odds;
    cand -= 2 * (min_to_all - k);
    M = cand;
  }
  int m = -1;
  dp[0] = 1;
  for (auto P : cnt_lens) {
    int len = P.st;
    int mult = P.nd;
    REP (bit, 20) {
      int ziom = min(mult, 1 << bit);
      if (ziom) {
        dp = dp | (dp << (ziom * len));
      }
      mult -= ziom;
    }
    //~ REP (rem, len) {
      //~ pref[0] = dp[rem];
      //~ for (int i = 1; i * len + rem <= n; i++) {
        //~ pref[i] = pref[i - 1] + dp[i * len + rem];
        //~ int to_sub = 0;
        //~ if (i >= mult + 1) {
          //~ to_sub = pref[i - mult - 1];
        //~ }
        //~ if (pref[i - 1] != to_sub) {
          //~ dp[i * len + rem] = 1;
        //~ }
      //~ }
    //~ }
  }
  //~ RE (i, n) {
    //~ debug(i, dp[i]);
  //~ }
  
  
  
  cout<<k + 1 - dp[k]<<" "<<M<<endl;
  
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}