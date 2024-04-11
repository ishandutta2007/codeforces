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

struct Node {
  int best_suf, sum;
  Node() {
    best_suf = 0, sum = 0;
  }
};

Node Merge(Node a, Node b) {
  Node n;
  n.best_suf = max(b.best_suf, b.sum + a.best_suf);
  n.sum = a.sum + b.sum;
  return n;
}

const int M = 1 << 16;
Node drz[2 * M + 5];
void Add(int a, int v) {
  a += M;
  drz[a].sum += v;
  drz[a].best_suf = drz[a].sum;
  a /= 2;
  while (a) {
    drz[a] = Merge(drz[2 * a], drz[2 * a + 1]);
    a /= 2;
  }
}

int Read(int a) {
  a += M;
  Node n = drz[a];
  while (a) {
    if (a % 2 == 1) {
      n = Merge(drz[a - 1], n);
    }
    a /= 2;
  }
  return n.best_suf;
}
const int N = 36000;
const int K = 55;
int a[N];
int dp[N][K];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  // dp[s][k] -
  // jaka jest najwczesniejsza pozycja, ktora potrzebuje, aby miec score s uzywajac k pudelek
  
  int n, k;
  cin>>n>>k;
  RE (i, n) {
    cin>>a[i];
  }
  RE (layer, k) {
    REP (i, 2 * M + 5) {
      drz[i] = Node();
    }
    VI last_occ(n + 2, -1);
    RE (i, n) {
      if (last_occ[a[i]] != -1) {
        Add(last_occ[a[i]], -1);
      }
      Add(i, 1);
      last_occ[a[i]] = i;
      Add(i, -dp[i][layer - 1] + dp[i - 1][layer - 1]);
      dp[i][layer] = dp[i][layer - 1] + Read(i);
      cerr<<dp[i][layer]<<" ";
    }
    cerr<<endl;
  }
  cout<<dp[n][k]<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}