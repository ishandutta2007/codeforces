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
int p[N];
int wh[N];
VPII ans;
int n;
void Swap(int a, int b) {
  debug(a, b);
  if (a > b) { swap(a, b); }
  swap(wh[p[a]], wh[p[b]]);
  swap(p[a], p[b]);
  
  if ((a == 1 && b > n / 2) || (a <= n / 2 && b == n)) {
    debug("t1");
    ans.PB({a, b});
    return;
  }
  if ((a <= n / 2) && (b <= n / 2)) {
    debug("t2");
    ans.PB({a, n});
    ans.PB({b, n});
    ans.PB({a, n});
    return;
  }
  if (a > n / 2 && b > n / 2) {
    debug("t3");
    ans.PB({1, a});
    ans.PB({1, b});
    ans.PB({1, a});
    return;
  }
  debug("here");
  ans.PB({a, n});
  ans.PB({1, n});
  ans.PB({1, b});
  ans.PB({1, n});
  ans.PB({a, n});
}
  
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  cin>>n;
  RE (i, n) {
    cin>>p[i];
    wh[p[i]] = i;
  }
  FOR (i, n / 2 + 1, n) {
    int pos = wh[i];
    if (pos > n / 2) { continue; }
    while (p[pos] > n / 2) {
      Swap(p[pos], pos);
//       RE (j, n) {
//         cerr<<p[j]<<" ";
//       }
//       cerr<<endl;
//       debug(pos, p[pos]);
    }
  }
  RE (i, n) {
    assert((i <= n / 2) == (p[i] <= n / 2));
  }
  debug("huh");
  RE (i, n) {
    if (i != wh[i]) {
      Swap(i, wh[i]);
    }
  }
  cout<<SZ(ans)<<endl;
  for (auto x : ans) {
    cout<<x.st<<" "<<x.nd<<"\n";
  }
  
  
  
  
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}