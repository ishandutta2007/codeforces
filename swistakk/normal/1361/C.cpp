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

// struct Edge {
//   int to, p1, p2;
// };


struct Euler {
  struct Edge {
    int nei, nr, p1, p2;
  };
  vector<vector<Edge>> slo;
  vector<int> ans, used, deg, beg;
  int e_num, n;
  Euler() : e_num(0), n(0) {}
  void AddEdge(int a, int b, int p1, int p2) {
    e_num++;
    if (a >= n || b >= n) {
      n = max(a, b) + 1;
      slo.resize(n + 2);
      deg.resize(n + 2);
      beg.resize(n + 2);
    }
    used.PB(0);
    slo[a].PB({b, e_num, p1, p2});
    slo[b].PB({a, e_num, p2, p1});
    deg[a]++;
    deg[b]++;
  }
  vector<int> FindEuler(int root) { // if used many times, please clear ans, beg, used
    used.PB(0);
    assert(SZ(used) > e_num);
    RE (i, n) {
      if (deg[i] % 2 == 1) {
        return vector<int>();
      }
    }
    Go(root);
    return ans;
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
      ans.PB(e.p2);
      ans.PB(e.p1);
    }
  }
};
const int N = 1 << 20;
PII e[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  //vector<Edge> es;
  set<int> all;
  RE (i, n) {
    int a, b;
    cin>>a>>b;
    e[i] = {a, b};
    all.insert(a);
  }
//   if (SZ(all) == 1) {
//     cout<<"20\n";
//     
  vector<int> best_cyc;
  int kl = 0, kp = 20, faj = 0;
  while (kl <= kp) {
    int chk = (kl + kp) / 2;
    int pow = 1 << chk;
    Euler eul;
    RE (i, n) {
      int v1 = e[i].st & (pow - 1);
      int v2 = e[i].nd & (pow - 1);
      eul.AddEdge(v1, v2, 2 * i - 1, 2 * i);
    }
    auto cyc = eul.FindEuler(e[1].st & (pow - 1));
    if (SZ(cyc) != 2 * n) {
      kp = chk - 1;
//       cout<<chk - 1<<"\n";
//       for (auto v : best_cyc) {
//         cout<<v<<" ";
//       }
//       cout<<endl;
//       return 0;
    } else {
      kl = chk + 1;
      faj = chk;
      best_cyc = cyc;
//       best_cyc = cyc;
//       if (chk == 20) {
//         cout<<20<<endl;
//         for (auto v : best_cyc) {
//           cout<<v<<" ";
//         }
//         cout<<endl;
//         return 0;
//       }
    }
  }
  cout<<faj<<endl;
  for (auto v : best_cyc) {
    cout<<v<<" ";
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}