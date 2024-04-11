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

vector<int> solveSystem(vector<vector<int>> coefs, vector<int> values) {
  int N = SZ(coefs), M = SZ(coefs[0]);
  
  vector<bool> vis(N);
  VI wrow(M, -1);
  
  REP (col, M) {
    int which = -1;
    REP (row, N) {
      if (!vis[row] && coefs[row][col]) {
        which = row;
        break;
      }
    }
    
    if (which == -1) { continue; }
    vis[which] = true;
    wrow[col] = which;
    
    REP (row, N) {
      if (row == which) { continue; }
      int coef = 0;
      if (coefs[row][col]) {
        if (coefs[row][col] == coefs[which][col]) {
          coef = 2;
        } else {
          coef = 1;
        }
      }
      //-coefs[row][col] / coefs[which][col];
      REP (c, M) {
        coefs[row][c] += coef * coefs[which][c];
        coefs[row][c] %= 3;
      }
      values[row] += coef * values[which];
      values[row] %= 3;
    }
  }
  
  REP (row, N) {
    if (!vis[row] && values[row]) { return {}; }
  }
  
  vector<int> result(M);
  REP (col, M) {
    if (wrow[col] != -1) {
      result[col] = values[wrow[col]] * coefs[wrow[col]][col] % 3;
    }
  }
  return result;
}


struct Sol {
  void Test() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> coefs;
    vector<int> values;
    vector<VI> mat(n + 2, VI(n + 2));
    RE (i, m) {
      int a, b, c;
      cin>>a>>b>>c;
      mat[a][b] = mat[b][a] = i;
      if (c != -1) {
        coefs.PB(vector<int>(m + 1));
        coefs.back()[i] = 1;
        values.PB(c - 1);
      }
    }
    RE (i, n) {
      RE (j, i - 1) {
        RE (k, j - 1) {
          if (mat[i][j] && mat[j][k] && mat[k][i]) {
            coefs.PB(vector<int>(m + 1));
            coefs.back()[mat[i][j]] = 1;
            coefs.back()[mat[k][j]] = 1;
            coefs.back()[mat[i][k]] = 1;
            values.PB(0);
          }
        }
      }
    }
    if (values.empty()) {
      RE (i, m) {
        cout<<1<<" ";
      }
      cout<<"\n";
      return;
    }
    vector<int> res = solveSystem(coefs, values);
    if (res.empty()) {
      cout<<"-1\n";
    } else {
      RE (i, m) {
        cout<<res[i] + 1<<" ";
      }
      cout<<"\n";
    }
    
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