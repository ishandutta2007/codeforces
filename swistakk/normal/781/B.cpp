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

    
const int N = 1e3 + 5;
//~ struct Info {
  //~ int nr;
  //~ char fir, sec;
//~ };
map<string, map<char, vector<pair<char, int>>>> mapuj;
string ans[N];
string s[N], t[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, n) {
    cin>>s[i]>>t[i];
    mapuj[s[i].substr(0, 2)][s[i][2]].PB({t[i][0], i});
    ans[i] = s[i].substr(0, 2);
  }
  
  bool fail = false;
  for (auto outer : mapuj) {
    set<char> taken;
    for (auto inner : outer.nd) {
      auto& v = inner.nd;
      if (SZ(v) >= 2) {
        for (auto p : v) {
          if (taken.count(p.st)) {
            fail = true;
            goto A;
          }
          taken.insert(p.st);
          ans[p.nd] += p.st;
        }
      }
    }
    while (1) {
      int forced = 0;
      for (auto inner : outer.nd) {
        auto& v = inner.nd;
        if (SZ(v) >= 2) { continue; }      
        int ind = v[0].nd;
        if (SZ(ans[ind]) >= 3) { continue; }
        if (taken.count(inner.st)) {
          forced++;
          if (taken.count(v[0].st)) {
            fail = true;
            goto A;
          }
          taken.insert(v[0].st);
          ans[v[0].nd] += v[0].st;
        }
      }
      if (forced == 0) {
        break;
      }
    }
    for (auto inner : outer.nd) {
      auto& v = inner.nd;
      if (SZ(v) >= 2) { continue; }
      int ind = v[0].nd;
      if (SZ(ans[ind]) >= 3) { continue; }
      assert(taken.count(inner.st) == 0);
      taken.insert(inner.st);
      ans[v[0].nd] += inner.st;
    }
  }
  
  
  
  A: ;
  if (!fail) {
    cout<<"YES\n";
    RE (i, n) {
      cout<<ans[i]<<"\n";
    }
  } else {
    cout<<"NO\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}