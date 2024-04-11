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
int n, m;
PII Coords(int guy) {
  return {(guy - 1) / m + 1, (guy - 1) % m + 1};
}
bool Neis(int g1, int g2) {
  PII c1 = Coords(g1);
  PII c2 = Coords(g2);
  return (abs(c1.st - c2.st) + abs(c1.nd - c2.nd)) == 1;
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  cin>>n>>m;
  //int all = n * m;
  VI guys(n * m);
  iota(ALL(guys), 1);
  random_shuffle(ALL(guys));
  //vector<PII> to_move;
  vector<vector<int>> board(n + 2, VI(m + 2));
  REP (i, n * m) {
    board[i / m + 1][i % m + 1] = guys[i];
  }
  
  function<PII()> GetAny = [&]() {
    RE (i, n - 1) {
      RE (j, m) {
        if (Neis(board[i][j], board[i + 1][j])) {
          return PII{i, j};
        }
      }
    }
    RE (j, m - 1) {
      RE (i, n) {
        if (Neis(board[i][j + 1], board[i][j])) {
          return PII{i, j};
        }
      }
    }
    return PII{-1, -1};
  };
  while (clock() < 1.8  * CLOCKS_PER_SEC) {
    PII to_move = GetAny();
    if (to_move.st == -1) {
      cout<<"YES\n";
      RE (i, n) {
        RE (j, m) {
          cout<<board[i][j]<<" ";
        }
        cout<<"\n";
      }
      return 0;
    }
    int i = rand() % n + 1;
    int j = rand() % m + 1;
    swap(board[i][j], board[to_move.st][to_move.nd]);
  }
  cout<<"NO\n";
    

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}