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

int k;
bool CanWin(string s) {
  int n = SZ(s) - 1;
  int first_zero = -1, last_zero = -1, first_one = -1, last_one = -1;
  RE (i, n) {
    if (s[i] == '0') {
      if (first_zero == -1) {
        first_zero = i;
      }
      last_zero = i;
    } else {
      if (first_one == -1) {
        first_one = i;
      }
      last_one = i;
    }
  }
  RE (p, n - k + 1) {
    int my_last = p + k - 1;
    if (p <= first_one && last_one <= my_last) {
      return 1;
    }
    if (p <= first_zero && last_zero <= my_last) {
      return 1;
    }
  }
  return 0;
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n>>k;
  string s;
  cin>>s;
  string F = "tokitsukaze", S = "quailty";
  if (s == string(n, '0') || s == string(n, '1')) {
    cout<<F<<endl;
    return 0;
  }
  s = "$" + s;
  int first_zero = -1, last_zero = -1, first_one = -1, last_one = -1;
  RE (i, n) {
    if (s[i] == '0') {
      if (first_zero == -1) {
        first_zero = i;
      }
      last_zero = i;
    } else {
      if (first_one == -1) {
        first_one = i;
      }
      last_one = i;
    }
  }
  int can_draw = 0;
  RE (p, n - k + 1) {
    int my_last = p + k - 1;
    if (p <= first_one && last_one <= my_last) {
      cout<<F<<endl;
      return 0;
    }
    if (p <= first_zero && last_zero <= my_last) {
      cout<<F<<endl;
      return 0;
    }
    if (p > 1 && my_last < n) {
      int is_mixed = (first_one < p && first_zero < p) || (last_one > my_last && last_zero > my_last);
      if (is_mixed) {
        can_draw = 1;
      } else {
        if (p > k && n - my_last > k) {
          can_draw = 1;
        }
      }
      debug(p,can_draw);
    }
  }
  string s1 = s, s2 = s, s3 = s, s4 = s;
  RE (i, k) {
    s1[i] = '0';
  }
  RE (i, k) {
    s2[i] = '1';
  }
  FOR (i, n - k + 1, n) {
    s3[i] = '0';
  }
  FOR (i, n - k + 1, n) {
    s4[i] = '1';
  }
  
  if (can_draw || !CanWin(s1) || !CanWin(s2) || !CanWin(s3) || !CanWin(s4)) {
    cout<<"once again\n";
    return 0;
  } else {
    cout<<S<<endl;
  }
  
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}