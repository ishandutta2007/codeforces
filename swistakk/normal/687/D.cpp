#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
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

const int N = 1e3 + 5;
int rep[2 * N];
int Find(int v) {
  if (rep[v] == v) {
    return v;
  }
  return rep[v] = Find(rep[v]);
}
void Union(int a, int b) { // czy sa w tej samej
  a = Find(a);
  b = Find(b);
  rep[a] = b;
}
PII cities[N * N];
int uu[N * N], vv[N * N], cc[N * N], ind[N * N];
int32_t main() {

//   ios_base::sync_with_stdio(0);
//   cout << fixed << setprecision(10);
//   cerr << fixed << setprecision(10);
//   cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  

  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  //cin>>n>>m>>q;
  vector<PII> es;
  RE (i, m) {
    int a, b, q;
    scanf("%d%d%d", &a, &b, &q);
    //cin>>a>>b>>q;
    if (a > b) {
      swap(a, b);
    }
    cities[i] = {a, b};
    es.PB({q, i});
  }
  sort(ALL(es));
  reverse(ALL(es));
  for (int i = 0; i < SZ(es); i++) {
    uu[i] = cities[es[i].nd].st;
    vv[i] = cities[es[i].nd].nd;
    cc[i] = es[i].st;
    ind[i] = es[i].nd;
  }
  map<PII, int> res;
  RE (i, q) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (res.count({a, b})) {
      cout<<res[{a, b}]<<"\n";
      continue;
    }
    REP (i, 2 * n + 2) {
      rep[i] = i;
    }
    int r = -1;
    for (int i = 0; i < SZ(es); i++) {
      if (ind[i] >= a && ind[i] <= b) {
        Union(2 * uu[i] - 1, 2 * vv[i]);
        Union(2 * uu[i], 2 * vv[i] - 1);
        if (Find(2 * uu[i]) == Find(2 * uu[i] - 1)) {
          r = cc[i];
          break;
        }
      }
    }
    printf("%d\n", r);
    res[{a, b}] = r;
  }
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}