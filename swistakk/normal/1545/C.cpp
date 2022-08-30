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

const int P = 998244353;
struct Sol {
  void Test() {
    int n;
    cin>>n;
    VVI arrs;
    VVI cnt(n + 2, VI(n + 2));
    RE (i, 2 * n) {
      VI arr;
      REP (j, n) {
        int a;
        cin>>a;
        arr.PB(a);
        cnt[j][a]++;
      }
      arrs.PB(arr);
    }
    VI alive(2 * n, 1);
    
    VVI conf(2 * n, VI(2 * n));
    REP (i, 2 * n) {
      REP (j, 2 * n) {
        if (i == j) {
          //cout<<"0";
        } else {
          REP (k, n) {
            if (arrs[i][k] == arrs[j][k]) {
              //cout<<"1";
              conf[i][j] = 1;
              //goto End;
            }
          }
          //cout<<"0";
          //End: ;
        }
      }
      //cout<<"\n";
    }
    VI take;
    while (1) {
      int found = -1;
      REP (pos, n) {
        RE (val, n) {
          if (cnt[pos][val] == 1) {
            REP (who, 2 * n) {
              if (alive[who] && arrs[who][pos] == val) {
                take.PB(who);
                found = who;
                goto End;
              }
            }
          }
        }
      }
      End: ;
      if (found == -1) { break; }
      VI to_erase{found};
      REP (i, 2 * n) {
        if (conf[found][i] && alive[i]) {
          to_erase.PB(i);
        }
      }
      for (auto er : to_erase) {
        alive[er] = 0;
        REP (i, n) {
          cnt[i][arrs[er][i]]--;
        }
      }
    }
    int res = 1;
    VI rep(2 * n);
    iota(ALL(rep), 0);
//     function<int(int)> Find = [&](int x) {
//       if (rep[x] == x) { return x; }
//       return rep[x] = Find(rep[x]);
//     };
//     function<bool(int, int)> Union = [&](int a, int b) {
//       a = Find(a);
//       b = Find(b);
//       if (a == b) { return false; }
//       rep[b] = a;
//       return true;
//     };
    VI vis(2 * n);
    function<void(int, int)> Dfs = [&](int v, int par) {
      if (par == 0) {
        take.PB(v);
      }
      vis[v] = 1;
      REP (i, 2 * n) {
        if (vis[i]) { continue; }
        if (conf[v][i] && alive[i]) {
          Dfs(i, par ^ 1);
        }
      }
    };
//     int ccs = 0;
//     REP (i, 2 * n) {
//       if (alive[i]) {
//         ccs++;
//       }
//     }
//     assert(ccs % 2 == 0);
    REP (i, n) {
      RE (j, n) {
        assert(cnt[i][j] == 0 || cnt[i][j] == 2);
      }
    }
    
    REP (i, 2 * n) {
      if (alive[i] && !vis[i]) {
        Dfs(i, 0);
        res = res * 2 % P;
      }
    }
    assert(SZ(take) == n);
    cout<<res<<"\n";
    for (auto x : take) {
      cout<<x + 1<<" ";
    }
    cout<<"\n";
//     REP (i, 2 * n) {
//       REP (j, 2 * n) {
//         if (i == j) { continue; }
//         if (alive[i] && alive[j] && conf[i][j]) {
//           cnt
      
    
    
    
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
  RE (_, t) {
    Sol sol;
    sol.Test();
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}