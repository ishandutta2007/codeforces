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

    
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, t;
  cin>>n>>t;
  
  VI before{0}, after;
  int was_dot = false;
  REP (i, n) {
    char c;
    cin>>c;
    if (c == '.') {
      was_dot = true;
    } else {
      if (!was_dot) {
        before.PB(c - '0');
      } else {
        after.PB(c - '0');
      }
    }
  }
  debug(before, after);
  
  int prvnon4 = 0;
  int len4 = 0;
  int best = -1;
  FORD (i, SZ(after) - 1, 0) {
    if (after[i] == 4) {
      len4++;
    } else {
      prvnon4 = after[i];
      len4 = 0;
    }
    if (len4 < t && prvnon4 >= 5) {
      best = i;
    }
  }
  debug(best);
  int where_dot = SZ(before);
  int B = SZ(before);
  before.insert(before.end(), ALL(after));
  int last = SZ(before) - 1;
  if (best != -1) {
    int ind = B + best - 1;
    last = ind;
    while (1) {
      debug(ind);
      before[ind]++;
      if (before[ind] == 10) {
        before[ind] = 0;
      } else {
        break;
      }
      ind--;
    }
  }
    
  bool put_dot = false;
  vector<char> ans;
  for (int i = 0; i <= last; i++) {
    if (i || before[i]) {
      ans.PB(before[i] + '0');
     // cout<<before[i];
    }
    if (i == where_dot - 1 && i < last) {
      ans.PB('.');
      put_dot = true;
      //cout<<".";
    }
  }
  while (put_dot && (ans.back() == '.' || ans.back() == '0')) {
    char c = ans.back();
    ans.pop_back();
    if (c == '.') {
      break;
    }
  }
  for (auto c : ans) {
    cout<<c;
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}