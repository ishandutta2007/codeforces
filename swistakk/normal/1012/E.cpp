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

const int N = 2e5 + 5;

struct Euler {
  struct Edge { int nei, nr, id; };
  vector<vector<Edge>> slo;
  VI ans, used, deg, beg;
  int e_num, n;
  Euler() : e_num(0), n(0) {}
  void AddEdge(int a, int b, int idd) {
    e_num++;
    if (a > n || b > n) {
      n = max(a, b);
      slo.resize(n + 2);
      deg.resize(n + 2);
      beg.resize(n + 2);
    }
    used.PB(0);
    slo[a].PB({b, e_num, idd});
    //slo[b].PB({a, e_num});
    //deg[a]++; deg[b]++;
  }
  VVI FindEuler() { // if used many times, please clear ans, beg, used
    used.PB(0);
    assert(SZ(used) > e_num);
    //RE (i, n) { if (deg[i] % 2 == 1) { return VI(); } }
    VVI lol;
    RE (i, n) {
      if (beg[i] < SZ(slo[i])) {
        Go(i);
        lol.PB(ans);
        ans.clear();
      }
    }
    //Go(1);
    return lol;
  }
private:
  void Go(int v) {
    debug(v);
    while (beg[v] < SZ(slo[v])) {
      Edge& e = slo[v][beg[v]];
      beg[v]++;
      int nei = e.nei;
      if (used[e.nr]) { continue; }
      used[e.nr] = 1;
      Go(nei);
      ans.PB(e.id);
      //ans.PB(nei);
    }
  }
};

int a[N];
int b[N];

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, s;
  cin>>n>>s;
  map<int, int> scal;
  RE (i, n) {
    cin>>a[i];
    scal[a[i]] = 1;
  }
  int nxt = 1;
  for (auto& p : scal) {
    p.nd = nxt;
    nxt++;
  }
  RE (i, n) {
    a[i] = scal[a[i]];
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  VVI where(n + 2);
  Euler euler;
  int moves = 0;
  RE (i, n) {
    if (a[i] == b[i]) { continue; }
    moves++;
    where[a[i]].PB(i);
    euler.AddEdge(a[i], b[i], i);
  }
  if (moves > s) {
    cout<<"-1\n";
    return 0;
  }
  
  VVI cycs = euler.FindEuler();
  int to_join = min(SZ(cycs), s - moves);
  if (to_join <= 2) { to_join = 0; }
//   debug(cycs);
//   //VVI mapuj;
//   for (auto& v : cycs) {
//     //VI nowy;
//     for (auto& x : v) {
//       int cp = x;
//       x = where[x].back();
//       where[cp].pop_back();
//     }
//     //reverse(ALL(v));
//   }
  debug(cycs);
  mini(to_join, SZ(cycs));
  VI bigger;
  VI begs;
  REP (i, to_join) {
    bigger.insert(bigger.end(), ALL(cycs.back()));
    begs.PB(cycs.back().back());
    cycs.pop_back();
  }
  if (to_join) {
    reverse(ALL(begs));
    cycs.PB(begs);
    cycs.PB(bigger);
  }
  cout<<SZ(cycs)<<endl;
  for (auto v : cycs) {
    cout<<SZ(v)<<"\n";
    for (auto x : v) {
      cout<<x<<" ";
    }
    int cp = a[v.back()];
    FORD (i, SZ(v) - 1, 1) {
      a[v[i]] = a[v[i - 1]];
    }
    a[v[0]] = cp;
    cout<<"\n";
  }
  RE (i, n) {
    cerr<<a[i]<<" ";
  }
  cerr<<endl;
  RE (i, n) {
    assert(a[i] == b[i]);
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}