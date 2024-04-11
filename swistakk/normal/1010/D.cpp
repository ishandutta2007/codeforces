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
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

const int N = 1e6 + 5;
string s[N];
int in[N];
int sons[N][2];
int par[N];
int eval[N];
int change[N];
int Eval(int v) {
  if (s[v] == "IN") {
    return eval[v] = in[v];
  }
  int s1 = Eval(sons[v][0]);
  if (s[v] == "NOT") {
    return eval[v] = !s1;
  }
  int s2 = Eval(sons[v][1]);
  if (s[v] == "AND") {
    return eval[v] = s1 & s2;
  } else if (s[v] == "OR") {
    return eval[v] = s1 | s2;
  } else {
    return eval[v] = s1 ^ s2;
  }
}
void Change(int v) {
  if (change[v] == 0 || s[v] == "IN") { return; }
  if (s[v] == "NOT") {
    change[sons[v][0]] = 1;
    Change(sons[v][0]);
  } else {
    REP (tr, 2) {
      int son = sons[v][tr];
      int brother = sons[v][tr ^ 1];
      int new_val;
      if (s[v] == "AND") {
        new_val = (eval[brother] & (eval[son] ^ 1));
      } else if (s[v] == "OR") {
        new_val = (eval[brother] | (eval[son] ^ 1));
      } else {
        new_val = eval[brother] ^ (eval[son] ^ 1);
      }
      if (new_val != eval[v]) {
        change[son] = 1;
      }
    }
    REP (tr, 2) {
      Change(sons[v][tr]);
    }
  }
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, n) {
    cin>>s[i];
    if (s[i] == "IN") {
      cin>>in[i];
    } else {
      int num_on_sons = 2;
      if (s[i] == "NOT") {
        num_on_sons = 1;
      }
      REP (tr, num_on_sons) {
        cin>>sons[i][tr];
        par[sons[i][tr]] = i;
      }
    }
  }
  int ans = Eval(1);
  change[1] = 1;
  Change(1);
  RE (i, n) {
    if (s[i] == "IN") {
      cout<<(change[i] ^ ans);
    }
  }
  cout<<endl;

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}