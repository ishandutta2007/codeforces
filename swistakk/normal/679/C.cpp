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

const int N = 5e2 + 5;
int sz_comp[N * N];
int cnt_comp[N * N];
int wh_cc[N][N];
int board[N][N];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int n;
bool OnBoard(int r, int c) {
  return r >= 1 && r <= n && c >= 1 && c <= n;
}
int Dfs(int r, int c, int heh) {
  wh_cc[r][c] = heh;
  int sz = 1;
  REP (dir, 4) {
    int nr = r + dr[dir];
    int nc = c + dc[dir];
    if (OnBoard(nr, nc) && wh_cc[nr][nc] == 0 && board[nr][nc] == 1) {
      sz += Dfs(nr, nc, heh);
    }
  }
  return sz;
}
int cur;
void UpdField(int r, int c, int sign, int inside) {
  if (!OnBoard(r, c)) { return; }
  if (board[r][c] == 0) { 
    if (inside) {
      cur += sign;
    }
    return;
  }
  int comp = wh_cc[r][c];
  if (cnt_comp[comp]) {
    cur -= sz_comp[comp];
  }
  cnt_comp[comp] += sign;
  if (cnt_comp[comp]) {
    cur += sz_comp[comp];
  }
}
  
  
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int k;
  cin>>n>>k;
  RE (i, n) {
    RE (j, n) {
      char c;
      cin>>c;
      if (c == '.') {
        board[i][j] = 1;
      }
    }
  }
  int nxt_c = 1;
  RE (i, n) {
    RE (j, n) {
      if (board[i][j] && wh_cc[i][j] == 0) {
        sz_comp[nxt_c] = Dfs(i, j, nxt_c);
        nxt_c++;
      }
      cerr<<wh_cc[i][j];
    }
    cerr<<endl;
  }
  int best = 0;
  RE (r, n - k + 1) {
    RE (c, n - k + 1) {
      if (c == 1) {
        FOR (rr, r, r + k - 1) {
          FOR (cc, c, c + k - 1) {
            UpdField(rr, cc, 1, 1);
            if (rr == r) {
              UpdField(rr - 1, cc, 1, 0);
              UpdField(rr + k, cc, 1, 0);
            }
          }
          UpdField(rr, c + k, 1, 0);
        }
      } else {
        FOR (rr, r, r + k - 1) {
          UpdField(rr, c + k - 1, -1, 0);
          UpdField(rr, c + k - 1,  1, 1);
          UpdField(rr, c - 1,     -1, 1);
          UpdField(rr, c - 1,      1, 0);
          UpdField(rr, c + k, 1, 0);
          UpdField(rr, c - 2, -1, 0);
        }
        UpdField(r - 1, c - 1, -1, 0);
        UpdField(r + k, c - 1, -1, 0);
        UpdField(r - 1, c + k - 1, 1, 0);
        UpdField(r + k, c + k - 1, 1, 0);
      }
      maxi(best, cur);
      debug(r, c, cur);
    }
    RE (i, n * n) {
      cnt_comp[i] = 0;
    }
    cur = 0;
  }
  cout<<best<<endl;
        
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}