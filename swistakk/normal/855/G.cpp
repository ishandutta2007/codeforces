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

//19:12
const int N = 1e5 + 5;
int par[N];
int rep[N];
int sum2[N];
int sz_cc[N];
int sz_sub[N];
int score[N];
int Find(int x) {
  if (rep[x] == x) { return x; }
  return rep[x] = Find(rep[x]);
}
int n;
int res;
int pre[N], post[N];
int d;
VI slo[N];
int IsAnc(int a, int b) {
  return pre[a] <= pre[b] && post[b] <= post[a];
}
void Union(int a, int b) { // a is parent
  a = Find(a);
  b = Find(b);
  assert(IsAnc(a, b));
  if (a == b) { return; }
  res -= score[a];
  res -= score[b];
  int lower = sz_sub[b];
  sum2[a] -= lower * lower;
  int upper = n - lower;
  sum2[b] -= upper * upper;
  sum2[a] += sum2[b];
  sz_cc[a] += sz_cc[b];
  int s = sz_cc[a];
  score[a] = s * (s - 1) * (s - 2) + 2 * s * (s - 1) * (n - s) + s * ((n - s) * (n - s) - sum2[a]);
  res += score[a];
  rep[b] = a;
}

void Dfs(int v) {
  sz_sub[v] = 1;
  d++;
  pre[v] = d;
  for (auto nei : slo[v]) {
    if (sz_sub[nei]) { continue; }
    par[nei] = v;
    Dfs(nei);
    sum2[v] += sz_sub[nei] * sz_sub[nei];
    sz_sub[v] += sz_sub[nei];
  }
  int upper = n - sz_sub[v];
  sum2[v] += upper * upper;
  int s = 1;
  score[v] = s * (s - 1) * (s - 2) + 2 * s * (s - 1) * (n - s) + s * ((n - s) * (n - s) - sum2[v]);
  res += score[v];
  d++;
  post[v] = d;
}
  
  
    
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  cin>>n;
  RE (i, n) {
    rep[i] = i;
    sz_cc[i] = 1;
  }
  RE (i, n - 1) {
    int a, b;
    cin>>a>>b;
    slo[a].PB(b);
    slo[b].PB(a);
  }
  Dfs(1);
  int q;
  cin>>q;
  cout<<res<<"\n";
  RE (i, q) {
    int a, b;
    cin>>a>>b;
    a = Find(a);
    b = Find(b);
    while (!IsAnc(a, b)) {
      Union(par[a], a);
      a = Find(a);
    }
    while (!IsAnc(b, a)) {
      Union(par[b], b);
      b = Find(b);
    }
    cout<<res<<"\n";
  }
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}