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
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }


int mul(int a, int b, int m) {
  int r = 0;
  while (b) {
    if (b % 2) {
      r = (r + a) % m;
    }
    a = 2 * a % m;
    b /= 2;
  }
  return r;
}

int spow(int a, int b, int m) {
  int r = 1;
  while (b) {
    if (b % 2) {
      r = mul(r, a, m);
    }
    a = mul(a, a, m);
    b /= 2;
  }
  return r;
}

struct Sol {
  void Test() {
    int n;
    cin>>n;
    int orig_n = n;
    int pot10 = (int)1e7;
    n *= pot10;
    int pot2_18 = 1 << 18;
    REP (milion, 10) {
      int rem = pot2_18 - (n % pot2_18);
      if (rem == pot2_18) { rem = 0; }
      if (rem % 10) { break; }
      debug("was");
      n += (int)1e6;
    }
    n = (n + pot2_18 - 1) / pot2_18 * pot2_18;
    debug(n);
    int pot5_18 = 1;
    int pot10_18 = 1;
    REP (i, 18) {
      pot5_18 *= 5;
      pot10_18 *= 10;
    }
    int r = n % pot5_18;
    int k = 0;
    if (r % 5 == 1) {
      k = 0;
    } else if (r % 5 == 2) {
      k = 1;
    } else if (r % 5 == 3) {
      k = 3;
    } else if (r % 5 == 4) {
      k = 2;
    } else {
      assert(false);
    }
    int pot5_pom = 1;
    RE (y, 17) {
      int fi = pot5_pom * 4;
      int to_mod = pot5_pom * 25;
      while (spow(2, k, to_mod) != r % to_mod) {
        k += fi;
      }
      pot5_pom *= 5;
    }
    k += pot5_pom * 20;
    debug(orig_n, spow(2, k, pot10_18)); 
    cout<<k<<"\n";
  }
  
  
};
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, n) {
    Sol sol;
    sol.Test();
  }

  
  
  return 0;
}