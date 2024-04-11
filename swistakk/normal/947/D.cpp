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
struct Wrap {
  string s;
  VI pref;
  VI suf;
  Wrap (string ss) {
    s = ss;
    int n = SZ(s);
    s = ' ' + s;
    pref.resize(n + 2);
    suf.resize(n + 2);
    RE (i, n) {
      pref[i] = pref[i - 1] + (s[i] == 'B' || s[i] == 'C');
      if (s[i] == 'A') {
        suf[i] = 1 + suf[i - 1];
      } else {
        suf[i] = 0;
      }
    }
  }
  int AskB(int a, int b) {
    return pref[b] - pref[a - 1];
  }
  int AskSuf(int a, int b) {
    return min(suf[b], b - a + 1);
  }
};
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  string s, t;
  cin>>s>>t;
  Wrap wraps(s), wrapt(t);
  int q;
  cin>>q;
  RE (i, q) {
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int nb1 = wraps.AskB(a, b);
    int sufa1 = wraps.AskSuf(a, b);
    int nb2 = wrapt.AskB(c, d);
    int sufa2 = wrapt.AskSuf(c, d);
    debug(nb1, sufa1, nb2, sufa2);
    if (nb1 % 2 != nb2 % 2 || nb1 > nb2 || sufa1 < sufa2) {
      cout<<"0";
      continue;
    }
    if (nb1 == 0 && nb2 == 0) {
      if (sufa1 % 3 == sufa2 % 3) {
        cout<<"1";
      } else {
        cout<<"0";
      }
      continue;
    }
    if (nb1 == 0) {
      if (sufa1 == sufa2) {
        cout<<"0";
      } else {
        cout<<"1";
      }
      continue;
    }
    if (nb1 == nb2) {
      if (sufa1 % 3 == sufa2 % 3) {
        cout<<"1";
      } else {
        cout<<"0";
      }
      continue;
    }
    cout<<"1";
    
//     if (sufa1 == sufa2) {
//       if (nb1 <= nb2 && nb1 % 2 == nb2 % 2) {
//         cout<<"1";
//       } else {
//         cout<<"0";
//       }
//     } else {
//       nb1 += 2;
//       if (nb1 <= nb2 && nb1 % 2 == nb2 % 2) {
//         cout<<"1";
//       } else {
//         cout<<"0";
//       }
//     }
  }
  cout<<endl;

  
  return 0;
}