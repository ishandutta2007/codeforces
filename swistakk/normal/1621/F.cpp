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

struct Sol {
  void Test() {
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    string s;
    cin>>s;
    if (n == 1) {
      cout<<"0\n";
      return;
    }
    vector<int> l0, l1;
    int c0 = 0, c1 = 0;
    int all0 = 0, all1 = 0;
    for (auto r : s) {
      if (r == '1') {
        all1++;
        if (c1) {
          c1++;
        } else {
          l0.PB(c0);
          c0 = 0;
          c1 = 1;
        }
      } else {
        all0++;
        if (c0) {
          c0++;
        } else {
          if (c1) {
            l1.PB(c1);
          }
          c1 = 0;
          c0 = 1;
        }
      }
    }
    if (c1) {
      l1.PB(c1);
    }
    l0.PB(c0);
    assert(SZ(l0) == SZ(l1) + 1);
    if (all1 == 0) {
      cout<<a<<"\n";
      return;
    }
    int free1 = 0;
    for (auto x : l0) {
      free1 += max(0ll, x - 1);
    }
    VI boki{l0[0], l0.back()};
    l0.pop_back();
    l0.erase(l0.begin());
    sort(ALL(l0));
    VI need(SZ(l0) + 1);
    RE (i, SZ(l0)) {
      need[i] = need[i - 1] + l0[i - 1];
    }
    int free2 = 0;
    for (auto x : l1) {
      free2 += x - 1;
    }
    debug(free1, free2);
    debug(l0, l1);
    int best = 0;
    debug(need);
    FOR (y, 0, all1) {
      FOR (xz, max(0ll, y - 1), min(all0, y + 1)) {
        debug(y, xz);
        if (free2 == 0 && xz == y - 1) { continue; }
        int need_merges = max(0ll, y - free2);
        debug(need_merges);
        if (need_merges >= SZ(need) || min(xz, y) < need[need_merges]) { continue; }
        assert(y != all1);
        maxi(need_merges, xz - free1);
        int cand = y * b + (xz - need_merges) * a - need_merges * c;
        maxi(best, cand);
      }
    }
    cout<<best<<endl;
  }
};

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int t;
  cin>>t;
  RE (i, t) {
    Sol sol;
    sol.Test();
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}