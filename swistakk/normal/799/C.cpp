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

int Best2(int money, VPII guys) {
  if (SZ(guys) < 2) {
    return -1e9;
  }
  int res = -1e9;
  int nxt_to_chk = 0;
  sort(ALL(guys), [&](PII a, PII b) {
    return a.nd < b.nd;
  });
  VI best_on_pref(SZ(guys));
  best_on_pref[0] = guys[0].st;
  FOR (i, 1, SZ(guys) - 1) {
    best_on_pref[i] = max(best_on_pref[i - 1], guys[i].st);
  }
  FORD (i, SZ(guys) - 1, 1) {
    while (nxt_to_chk < i && guys[nxt_to_chk].nd + guys[i].nd <= money) {
      nxt_to_chk++;
    }
    if (nxt_to_chk) {
      maxi(res, best_on_pref[min(nxt_to_chk - 1, i - 1)] + guys[i].st);
    }
  }
  return res;
}
int Best1(int money, VPII guys) {
  int res = -1e9;
  for (auto g : guys) {
    if (g.nd <= money) {
      maxi(res, g.st);
    }
  }
  return res;
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, c, d;
  cin>>n>>c>>d;
  VPII cs, ds;
  RE (i, n) {
    int b, p;
    char cc;
    cin>>b>>p>>cc;
    if (cc == 'C') {
      cs.PB({b, p});
    } else {
      ds.PB({b, p});
    }
  }
  int res = max(max(Best1(c, cs) + Best1(d, ds), Best2(c, cs)), Best2(d, ds));
  if (res > 0) {
    cout<<res<<endl;
  } else {
    cout<<"0"<<endl;
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}