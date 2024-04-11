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


int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  VVI slo(n + 2);
  VI indeg(n + 2);
  VVI trans(n + 2);
  RE (i, m) {
    int a, b;
    cin>>a>>b;
    slo[a].PB(b);
    trans[b].PB(a);
    indeg[b]++;
  }
  VI used(n + 2);
  
  RE (i, n) {
    int any_nei = 0;
    for (auto nei : slo[i]) {
      if (used[nei]) {
        any_nei = 1;
      }
    }
    for (auto nei : trans[i]) {
      if (used[nei]) {
        any_nei = 1;
      }
    }
    if (!any_nei) {
      used[i] = 1;
    }
  }
  while (1) {
    VI has_me_or_pred(n + 2);
    VI is_fine(n + 2);
VI ord(n + 2);
iota(ALL(ord), 1);
    RE (ii, n) {
int i = ord[ii - 1];
      if (used[i]) {
        has_me_or_pred[i] = 1;
      } else {
        for (auto nei : trans[i]) {
          if (used[nei]) {
            has_me_or_pred[i] = 1;
          }
        }
      }
    }
    RE (ii, n) {

int i = ord[ii - 1];
      if (has_me_or_pred[i]) {
        is_fine[i] = 1;
        for (auto nei : slo[i]) {
          is_fine[nei] = 1;
        }
      }
    }
    int all_fine = 1;
    RE (ii, n) {

int i = ord[ii - 1];
      if (!is_fine[i]) {
        all_fine = 0;
        int skip = 0;
        for (auto nei : trans[i]) {
          if (used[nei]) {
            skip = 1;
          }
        }
        if (!skip) {
          for (auto nei : slo[i]) {
            used[nei] = 0;
          }
          used[i] = 1;
        }
      }
    }
    if (all_fine) {
      int k = 0;
      RE (i, n) {
        if (used[i]) {
          k++;
        }
      }
      cout<<k<<endl;
      RE (i, n) {
        if (used[i]) {
          cout<<i<<" ";
        }
      }
      cout<<endl;
      return 0;
    }
  }
//   VI que;
//   RE (i, n) {
//     if (indeg[i] == 0) {
//       que.PB(i);
//     }
//   }
//   VI ans;
//   VI reachable(n + 2);
//   REP (i, SZ(que)) {
//     int v = que[i];
//     for (auto nei : slo[v]) {
//       indeg[nei]--;
//       if (indeg[nei] == 0) {
//         que.PB(nei);
//       }
//     }
//     if (reachable[v]) { continue; }
//     else {
//       ans.PB(v);
//       for (auto nei : slo[v]) {
//         reachable[nei] = 1;
//       }
//     }
//   }
//   sort(ALL(ans));
//   cout<<SZ(ans)<<endl;
//   for (auto x : ans) {
//     cout<<x<<" ";
//   }
//   cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}