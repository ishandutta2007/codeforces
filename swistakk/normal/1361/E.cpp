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

struct Sol {
  void Test() {
    int n, m;
    cin>>n>>m;
    VVI slo(n + 2);
    vector<PII> es;
    RE (i, m) {
      int a, b;
      cin>>a>>b;
      slo[a].PB(b);
      es.PB({b, a});
    }
    VI pre(n + 2), par(n + 2), sz(n + 2);
    int ziom = -1;
    VI ord;
    REP (tr, 40) {
      int root = 1 + rand() % n;
      RE (i, n) {
        pre[i] = 0;
        par[i] = 0;
        sz[i] = 0;
      }
      ord.clear();
      int d = 0;
      function<void(int)> Dfs = [&](int v) {
        d++;
        ord.PB(v);
        sz[v] = 1;
        pre[v] = d;
        for (auto nei : slo[v]) {
          if (pre[nei]) { continue; }
          par[nei] = v;
          Dfs(nei);
          sz[v] += sz[nei];
        }
      };
      Dfs(root);
      function<bool(int, int)> IsAncOf = [&](int a, int b) {
        return pre[a] <= pre[b] && pre[b] + sz[b] <= pre[a] + sz[a];
      };
      int fail = 0;
      RE (i, n) {
        for (auto nei : slo[i]) {
          if (!IsAncOf(nei, i) && par[nei] != i) {
            //debug(root, i, nei);
            fail = 1;
            goto A;
          }
        }
      }
      A: ;
      if (!fail) {
        ziom = root;
        break;
      }
    }
    debug(ziom);
    if (ziom == -1) {
      cout<<"-1\n";
      return;
    }
    int M = 1;
    while (M <= n) {
      M = 2 * M;
    }
    sort(ALL(es), [&](PII L, PII R) { return pre[L.st] < pre[R.st]; });
    vector<vector<int>> drz(2 * M + 5);
    REP (i, SZ(es)) {
      int ind = pre[es[i].nd] + M - 1;
      while (ind) {
        drz[ind].PB(i);
        ind /= 2;
      }
    }
    VI is_interesting(n + 2);
    function<void(vector<int>&, vector<int>&)> Merge = [&](vector<int>& v, vector<int>& from){
      REP (i, min(2ll, SZ(from))) {
        v.PB(from[i]);
      }
      sort(ALL(v));
      v.resize(min(2ll, SZ(v)));
    };
    for (auto v : ord) {
      if (v == ziom) {
        is_interesting[v] = 1;
        continue;
      }
      int L = pre[v] + M - 1;
      int R = pre[v] + sz[v] + M - 2;
      vector<int> here;
      Merge(here, drz[L]);
      if (L != R) {
        Merge(here, drz[R]);
      }
      while (L / 2 != R / 2) {
        if (L % 2 == 0) {
          Merge(here, drz[L + 1]);
        }
        if (R % 2 == 1) {
          Merge(here, drz[R - 1]);
        }
        L /= 2;
        R /= 2;
      }
      if (here.empty()) { continue; }
      int h1 = es[here[0]].st;
      if (SZ(here) == 2 && pre[es[here[1]].st] < pre[v]) { continue; }
      if (pre[h1] < pre[v]) {
        is_interesting[v] = is_interesting[h1];
      }
    }
    
    int cnt = 0;
    RE (i, n) {
      cnt += is_interesting[i];
    }
    debug(cnt);
    if (5 * cnt < n) {
      cout<<"-1\n";
      return;
    }
    //cout<<cnt<<"\n";
    RE (i, n) {
      if (is_interesting[i]) {
        cout<<i<<" ";
      }
    }
    cout<<endl;
  }
};


int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  

  int t;
  cin>>t;
  RE (i, t) {
    Sol sol;
    sol.Test();
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}