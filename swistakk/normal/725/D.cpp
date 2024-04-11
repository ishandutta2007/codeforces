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

const int N = 3e5 + 5;
PII p[N];
//int t[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, n) {
    int t, w;
    cin>>t>>w;
    p[i] = {t, w};
  }
  n++;
  p[n] = {0, 0}; 
  sort(p + 2, p + n + 1);
  
  multiset<int> zdupcone;
  multiset<int> waiting;
  int sum_zdupcone = 0;
  int best = n;
//   FOR (i, 2, n) {
//     if (t[i] > t[1]) {
//       best++;
//     }
//   }
  int last = -1;
  VI wait_to_wait;
  FORD (i, n, 2) {
    if (last != p[i].st) {
      for (auto x : wait_to_wait) {
        waiting.insert(x);
      }
      wait_to_wait.clear();
    }
    int wolne = p[1].st - p[i].st;
    wait_to_wait.PB(p[i].nd - p[i].st + 1);
    last = p[i].st;
    while (1) {
      if (waiting.empty() || zdupcone.empty()) { break; }
      int smallest_wait = *(waiting.begin());
      auto it = zdupcone.end();
      it--;
      if (smallest_wait >= *it) { break; }
      sum_zdupcone -= *it - smallest_wait;
      waiting.insert(*it);
      zdupcone.erase(it);
      zdupcone.insert(smallest_wait);
      waiting.erase(waiting.begin());
    }
    while (!waiting.empty() && wolne >= sum_zdupcone + *(waiting.begin())) {
      sum_zdupcone += *(waiting.begin());
      zdupcone.insert(*(waiting.begin()));
      waiting.erase(waiting.begin());
    }
    if (wolne >= 0) {
      mini(best, n - i - SZ(zdupcone) + 1);
    }
  }
  cout<<best<<endl;
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}