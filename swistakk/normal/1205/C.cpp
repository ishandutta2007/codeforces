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

const int N = 55;
int hidden[N][N];
int board[N][N];
int Ask(int i1, int j1, int i2, int j2) {
#ifndef LOCAL
  cout<<"? "<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<endl;
  int x;
  cin>>x;
  return x;
#else
  if (i1 + j1 + 2 == i2 + j2) { return hidden[i1][j1] == hidden[i2][j2]; }
  int di = (i2 - i1) / 3;
  int dj = (j2 - j1) / 3;
  return hidden[i1][j1] == hidden[i2][j2] && hidden[i1 + di][j1 + dj] == hidden[i1 + 2 * di][j1 + 2 * dj];
#endif
}
int di[] = {-2, -1, 0, 0, 1, 2};
int dj[] = {0, -1, 2, -2, 1, 0};
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, n) {
    RE (j, n) {
#ifdef LOCAL
      cin>>hidden[i][j];
#endif
      board[i][j] = -1;
    }
  }
  board[1][1] = 1;
  board[n][n] = 0;
  function<void(int, int)> Go = [&](int i, int j) {
    if (i + 1 == n && j + 1 == n) { return; }
    if (i == n || j == n) { return; }
    int pal = Ask(i, j, i + 1, j + 1);
    board[i + 1][j + 1] = board[i][j] ^ pal ^ 1;
    Go(i + 1, j + 1);
  };
  for (int i = 1; i < n; i += 2) {
    int pal = Ask(1, i, 1, i + 2);
    board[1][i + 2] = board[1][i] ^ pal ^ 1;
    Go(1, i + 2);
    pal = Ask(i, 1, i + 2, 1);
    board[i + 2][1] = board[i][1] ^ pal ^ 1;
    Go(i + 2, 1);
  }
  Go(1, 1);
  VPII que;
  VPII path;
  for (int i = 1; i <= n; i += 2) {
    path.PB({i, 1});
  }
  for (int i = 3; i <= n; i += 2) {
    path.PB({n, i});
  }
  for (int i = 0; i + 2 < SZ(path); i++) {
    int i1 = path[i].st;
    int j1 = path[i].nd;
    int i2 = path[i + 1].st;
    int j2 = path[i + 1].nd;
    int i3 = path[i + 2].st;
    int j3 = path[i + 2].nd;
    int i15 = (i1 + i2) / 2;
    int j15 = (j1 + j2) / 2;
    int i25 = (i2 + i3) / 2;
    int j25 = (j2 + j3) / 2;
    if (board[i1][j1] != board[i3][j3]) {
      int pal = Ask(i15, j15, i25, j25);
      if (pal == (board[i1][j1] == board[i2][j2])) {
        int heh = Ask(i1, j1, i25, j25);
        board[i25][j25] = board[i1][j1] ^ heh ^ 1;
        board[i15][j15] = board[i2][j2] ^ heh ^ 1;
      } else {
        int heh = Ask(i15, j15, i3, j3);
        board[i15][j15] = board[i3][j3] ^ heh ^ 1;
        board[i25][j25] = board[i2][j2] ^ heh ^ 1;
      }
      que.PB({i15, j15});
      break;
    }
  }
  assert(!que.empty());
//   for (int i = 1; i + 4 <= n; i += 2) {
//     if (board[i][1] != board[i + 4][1]) {
//       int pal = Ask(i + 1, 1, i + 3, 1);
//       if (pal == (board[i][1] == board[i + 2][1])) {
//         int heh = Ask(i, 1, i + 3, 1);
//         board[i + 3][1] = board[i][1] ^ heh ^ 1;
//         board[i + 1][1] = board[i + 2][1] ^ heh ^ 1;
//       } else {
//         int heh = Ask(i + 1, 1, i + 4, 1);
//         board[i + 1][1] = board[i + 4][1] ^ heh ^ 1;
//         board[i + 3][1] = board[i + 2][1] ^ heh ^ 1;
//       }
//       que.PB({i + 1, 1});
//       break;
//     }
//     if (board[n][i] != board[n][i + 4]) {
//       int pal = Ask(n, i + 1, n, i + 3);
//       if (pal == (board[n][i] == board[n][i + 2])) {
//         int heh = Ask(n, i, n, i + 3);
//         board[n][i + 3] = board[n][i] ^ heh ^ 1;
//         board[n][i + 1] = board[n][i + 2] ^ heh ^ 1;
//       } else {
//         int heh = Ask(n, i + 1, n, i + 4);
//         board[n][i + 1] = board[n][i + 4] ^ heh ^ 1;
//         board[n][i + 3] = board[n][i + 2] ^ heh ^ 1;
//       }
//       que.PB({n, i + 1});
//       break;
//     }
//   }
//   if (que.empty()) {
//     assert(board[
  for (int ii = 0; ii < SZ(que); ii++) {
    int i = que[ii].st;
    int j = que[ii].nd;
    for (int dir = 0; dir < 6; dir++) {
      int ni = i + di[dir];
      int nj = j + dj[dir];
      if (ni < 1 || nj < 1) { continue; } 
      if (board[ni][nj] != -1) { continue; }
      if (ni + nj < i + j) {
        board[ni][nj] = board[i][j] ^ Ask(ni, nj, i, j) ^ 1;
      } else {
        board[ni][nj] = board[i][j] ^ Ask(i, j, ni, nj) ^ 1;
      }
      que.PB({ni, nj});
    }
  }
  cout<<"!\n";
  RE (i, n) {
    RE (j, n) {
      cout<<board[i][j];
    }
    cout<<endl;
  }
  #ifdef LOCAL
  RE (i, n) {
    RE (j, n) {
      assert(board[i][j] == hidden[i][j]);
      
    }
  }
  #endif
  return 0;
}