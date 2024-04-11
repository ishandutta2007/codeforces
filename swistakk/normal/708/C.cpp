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

const int N = 5e5 + 5;
int vis[N][2];
int sz[N][2];
VI slo[N];
int sub[N];
int n;
VI cents;
void Dfs(int v, int nr, int subtree, int root) {
  vis[v][nr] = 1;
  sz[v][nr] = 1;
  if (v != root && subtree == 0) {
    subtree = v;
  }
  sub[v] = subtree;
  bool bad = false;
  for (auto nei : slo[v]) {
    if (vis[nei][nr]) { continue; }
    Dfs(nei, nr, subtree, root);
    if (sz[nei][nr] * 2 > n) {
      bad = true;
    }
    sz[v][nr] += sz[nei][nr];
  }
  if (2 * (n - sz[v][nr]) > n) {
    bad = true;
  }
  if (!bad) {
    cents.PB(v);
  }
}
    
    
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  cin>>n;
  RE (i, n - 1) {
    int a, b;
    cin>>a>>b;
    slo[a].PB(b);
    slo[b].PB(a);
  }
  Dfs(1, 0, 0, 1);
  assert(SZ(cents) >= 1 && SZ(cents) <= 2);
  if (SZ(cents) == 2) {
    REP (i, n) {
      cout<<"1 ";
    }
    cout<<endl;
    return 0;
  }
  Dfs(cents[0], 1, 0, cents[0]);
  VPII ch_sz;
  for (auto ch : slo[cents[0]]) {
    ch_sz.PB({sz[ch][1], ch});
  }
  sort(ALL(ch_sz));
  reverse(ALL(ch_sz));
  RE (v, n) {
    if (v == cents[0]) {
      cout<<"1 ";
      continue;
    }
    int upper = n - sz[v][1];
    if (sub[v] == ch_sz[0].nd) {
      upper -= ch_sz[1].st;
    } else {
      upper -= ch_sz[0].st;
    }
    if (2 * upper <= n) {
      cout<<"1 ";
    } else {
      cout<<"0 ";
    }
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}