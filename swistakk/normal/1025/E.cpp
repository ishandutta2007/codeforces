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

const int kDir = 4;
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
const int N = 55;
PII par[N][N];
int vis[N][N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  function<bool(int)> Valid = [&](int k) {
    return k >= 1 && k <= n;
  };
  function<VVI(VI, VI)> Solve = [&](VI si, VI sj) {
    vector<VI> board(n + 2, VI(n + 2));
    vector<int> gotten(m + 2);
    RE (i, m) {
      board[si[i]][sj[i]] = i;
      if (si[i] == i && sj[i] == i) {
        gotten[i] = 1;
      }
    }
    VVI res;
    function<void(int, int, int, int)>  Move = [&](int i1, int j1, int i2, int j2) {
      assert(abs(i1 - i2) + abs(j1 - j2) == 1);
      assert(board[i1][j1] != 0);
      assert(board[i2][j2] == 0);
      res.PB({i1, j1, i2, j2});
      int cube = board[i1][j1];
      swap(board[i1][j1], board[i2][j2]);
      assert(Valid(i1) && Valid(i2) && Valid(j1) && Valid(j2));
      si[cube] = i2;
      sj[cube] = j2;
    };
    while (1) {
      int sup = 1;
      RE (i, m) {
        if (gotten[i]) { continue; }
        sup = 0;
        if (si[i] == sj[i]) {
          REP (dir, kDir) {
            int ni = si[i] + di[dir];
            int nj = sj[i] + dj[dir];
            if (Valid(ni) && Valid(nj) && board[ni][nj] == 0) {
              Move(si[i], sj[i], ni, nj);
              break;
            }
          }
        }
      }
      if (sup) { break; }
      //int wh_shortest = -1;
      VPII best_path;
      RE (i, m) {
        if (gotten[i]) { continue; }
        vector<PII> que;
        que.PB({si[i], sj[i]});
        if (board[i][i]) { continue; }
        //PII target = {i, i};
        RE (j, n) {
          RE (k, n) {
            vis[j][k] = 0;
          }
        }
        vis[si[i]][sj[i]] = 1;
        for (int ii = 0; ii < SZ(que); ii++) {
          PII ziom = que[ii];
          debug(ziom);
          REP (dir, kDir) {
            int ni = ziom.st + di[dir];
            int nj = ziom.nd + dj[dir];
            if (!Valid(ni) || !Valid(nj) || board[ni][nj] || vis[ni][nj]) { continue; }
            que.PB({ni, nj});
            par[ni][nj] = ziom;
            vis[ni][nj] = 1;
            if (ni == i && nj == i) {
              int ci = i, cj = i;
              VPII path;
              while (ci != si[i] || cj != sj[i]) {
                debug(ci, cj);
                path.PB({ci, cj});
                PII prv = par[ci][cj];
                ci = prv.st;
                cj = prv.nd;
              }
              path.PB({si[i], sj[i]});
              if (best_path.empty() || SZ(path) < SZ(best_path)) {
                best_path = path;
              }
              goto End;
            }
            
          }
        }
        End: ;
      }
      reverse(ALL(best_path));
      debug(best_path);
      RE (i, SZ(best_path) - 1) {
        Move(best_path[i - 1].st, best_path[i - 1].nd, best_path[i].st, best_path[i].nd);
      }
      gotten[best_path.back().st] = 1;
    }
    debug(res);
    return res;
  };
  VI si(m + 2), sj(m + 2);
  RE (i, m) {
    cin>>si[i]>>sj[i];
  }
  VI ti(m + 2), tj(m + 2);
  RE (i, m) {
    cin>>ti[i]>>tj[i];
  }
  
  VVI s1 = Solve(si, sj);
  VVI s2 = Solve(ti, tj);
  reverse(ALL(s2));
  for (auto& v : s2) {
    swap(v[0], v[2]);
    swap(v[1], v[3]);
  }
  cout<<SZ(s1) + SZ(s2)<<endl;
  s1.insert(s1.end(), ALL(s2));
  for (auto p : s1) {
    for (auto w : p) {
      cout<<w<<" ";
    }
    cout<<"\n";
  }
//   for (auto p : s2) {
//     for (auto w : p) {
//       cout<<w<<" ";
//     }
//     cout<<"\n";
//   }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}