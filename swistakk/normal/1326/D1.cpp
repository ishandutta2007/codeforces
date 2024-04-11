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

struct Manacher {
  // IGNORES FIRST LETTER - in[0] must be space
  // par[i] = k <=> [i - k + 1, i + k] is maximal palindrome
  // npar[i] = k <=> [i - k, i + k] is maximal palindrome
  vector<int> par, npar;
  Manacher(string in) {
    assert(in[0] == ' ');
    int orig_n = SZ(in) - 1;
    string s = " #";
    for (int i = 1; i <= orig_n; i++) {
      s += in[i];
      s += '#';
    }
    s += '$';
    int new_n = SZ(s) - 2;
    npar.resize(new_n + 2);
    int furth_beg = 0;
    int furth_end = 0;
    for (int i = 1; i <= new_n; i++) {
      if (furth_end < i) {
        furth_beg = i;
        furth_end = i;
      }
      int corr_npar = furth_beg + furth_end - i;
      if (furth_end > i + npar[corr_npar]) {
        npar[i] = npar[corr_npar];
      } else {
        npar[i] = furth_end - i;
        furth_beg = i - npar[i];
        while (s[furth_beg - 1] == s[furth_end + 1]) {
          furth_beg--;
          furth_end++;
          npar[i]++;
        }
      }
    }
    par.resize(orig_n + 2);
    for (int i = 1; i <= orig_n; i++) {
      if (i < orig_n) {
        par[i] = npar[2 * i + 1] / 2;
      }
      npar[i] = npar[2 * i] / 2;
    }
    npar.resize(orig_n + 2);
  }
};

int PalPref(string s) {
  int n = SZ(s);
  s = " " + s; 
  Manacher man(s);
  int res = 0;
  RE (i, n) {
    if (man.par[i] == i) {
      maxi(res, 2 * i);
    }
    if (man.npar[i] == i - 1) {
      maxi(res, 2 * i - 1);
    }
  }
  return res;
}
  
  
  
  

struct Sol {
  void Test() {
    string s;
    cin>>s;
    int n = SZ(s);
    int l = 0, r = n - 1;
    //int res = 0;
    int cut_len = 0;
    while (l < r && s[l] == s[r]) {
      cut_len++;
      l++;
      r--;
    }
    if (l > r) {
      cout<<s<<"\n";
      return;
    }
//     if (l == n) {
//       cout<<res<<"\n";
//       return;
//     }
    string s1 = s.substr(l, r - l + 1);
    string s2 = s1;
    reverse(ALL(s2));
    //assert(SZ(s2) == n - l);
    //reverse(ALL(s1));
    int p1 = PalPref(s1);
    int p2 = PalPref(s2);
    debug(cut_len, s1, p1, s2, p2);
    if (p1 >= p2) {
      cout<<s.substr(0, cut_len + p1) + s.substr(r + 1)<<"\n";
    } else {
      cout<<s.substr(0, cut_len) + s.substr(r + 1 - p2)<<"\n";
    }
    //cout<<res + max(PalPref(s1), PalPref(s2))<<"\n";
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