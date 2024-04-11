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

const int N = 1e6 + 6;
int s[N];
int t[N];

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  int control = 0;
  RE (i, n) {
    cin>>s[i];
    control += s[i];
  }
  RE (i, n) {
    cin>>t[i];
    control -= t[i];
  }
  if (control) {
    cout<<"NO\n";
    return 0;
  }
  //sort(s + 1, s + 1 + n);
  sort(t + 1, t + 1 + n);
  vector<VI> stones;
  RE (i, n) {
    stones.PB({s[i], i});
  }
  sort(ALL(stones));
  REP (i, n) {
    stones[i].PB(t[i + 1]);
    swap(stones[i][1], stones[i][2]);
  }
  debug(stones);
  int bil = 0;
  vector<VI> to_right, to_left;
  for (auto stone : stones) {
    bil += stone[1] - stone[0];
    if (bil < 0) {
      cout<<"NO\n";
      return 0;
    }
    if (stone[0] < stone[1]) {
      to_right.PB(stone);
    } else if (stone[0] > stone[1]) {
      to_left.PB(stone);
    }
  }
  reverse(ALL(to_left));
  reverse(ALL(to_right));
  cout<<"YES\n";
  vector<VI> ans;
  while (!to_left.empty()) {
    int i = to_right.back()[2];
    int j = to_left.back()[2];
    int go_i = to_right.back()[1] - to_right.back()[0];
    int go_j = to_left.back()[0] - to_left.back()[1];
    int go = min(go_i, go_j);
    ans.PB({i, j, go});
    //cout<<i<<" "<<j<<" "<<go<<"\n";
    to_right.back()[0] += go;
    to_left.back()[0] -= go;
    if (to_right.back()[0] == to_right.back()[1]) {
      to_right.pop_back();
    }
    if (to_left.back()[0] == to_left.back()[1]) {
      to_left.pop_back();
    }
  }
  cout<<SZ(ans)<<endl;
  for (auto x : ans) {
    for (auto y : x) {
      cout<<y<<" ";
    }
    cout<<"\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}