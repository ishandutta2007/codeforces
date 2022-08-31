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
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
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

const int M = 1 << 19;
const int N = 1e6 + 5;

int dis[N];
VI drz[2 * M + 5];
VI que;
void Put(int a, int b, int v) {
  a += M - 1;
  b += M - 1;
  drz[a].PB(v);
  if (a != b) {
    drz[b].PB(v);
  }
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      drz[a + 1].PB(v);
    }
    if (b % 2 == 1) {
      drz[b - 1].PB(v);
    }
    a /= 2;
    b /= 2;
  }
}

int a[N], b[N], c[N], d[N];
bool Cmp(int x, int y) {
  return b[x] > b[y];
}
int par[N];
map<int, int> mapka;
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  set<int> used;
  make(int, n);
  RE (i, n) {
    cin>>a[i]>>b[i]>>c[i]>>d[i];
    used.insert(a[i]);
    used.insert(b[i]);
    used.insert(c[i]);
    used.insert(d[i]);
    if (a[i] == 0 && b[i] == 0) {
      que.PB(i);
      dis[i] = 1;
    }
  }
  int cur = 0;
  for (auto x : used) {
    cur++;
    mapka[x] = cur;
  }
  RE (i, n) {
    a[i] = mapka[a[i]];
    b[i] = mapka[b[i]];
    c[i] = mapka[c[i]];
    d[i] = mapka[d[i]];
    debug(a[i], b[i], c[i], d[i]);
    Put(a[i], 4 * n, i);
  }
  RE (i, 2 * M) {
    sort(ALL(drz[i]), Cmp);
  }
  for (int ii = 0; ii < SZ(que); ii++) {
    int v = que[ii];
    debug(v);
    int cc = c[v] + M - 1;
    while (cc) {
      while (!drz[cc].empty() && b[drz[cc].back()] <= d[v]) {
        int nei = drz[cc].back();
        if (dis[nei]) {
        } else {
          dis[nei] = dis[v] + 1;
          par[nei] = v;
          que.PB(nei);
        }
        drz[cc].pop_back();
      }
      cc /= 2;
    }
  }
        
  
  
  
  
  
  
  
  
  
  
  if (dis[n] == 0) {
    cout<<"-1\n";
  } else {
    cout<<dis[n]<<endl;
    int curv = n;
    VI path;
    while (curv) {
      path.PB(curv);
      curv = par[curv];
    }
    reverse(ALL(path));
    assert(SZ(path) == dis[n]);
    for (auto x : path) {
      cout<<x<<" ";
    }
    cout<<endl;
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}