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

    const int N = 1e3 + 5;
    int board[N][N], col[N], row[N];
    void Exit() {
      cout<<"-1"<<endl;
      exit(0);
    }
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  RE (i, n) {
    RE (j, m) {
      cin>>board[i][j];
    }
  }
  debug(n, m);
  RE (i, n) {
    RE (j, m) {
      cerr<<board[i][j]<<" ";
    }
    cerr<<endl;
  }
  int sw = 0;
  if (n > m) {
    RE (i, n) {
      RE (j, i) {
        swap(board[i][j], board[j][i]);
      }
    }
    swap(n, m);
    sw = 1;
  }
  debug(n, m);
  RE (i, n) {
    RE (j, m) {
      cerr<<board[i][j]<<" ";
    }
    cerr<<endl;
  }
  int wh_min = 1;
  RE (i, m) {
    if (board[1][i] < board[1][wh_min]) {
      wh_min = i;
    }
  }
  int ans = 0;
  RE (i, m) {
    col[i] = board[1][i] - board[1][wh_min];
    ans += col[i];
  }
  RE (i, n) {
    row[i] = board[i][1] - col[1];
    ans += row[i];
  }
  RE (i, n) {
    if (row[i] < 0) {
      Exit();
    }
  }
  RE (i, n) {
    RE (j, m) {
      if (board[i][j] != row[i] + col[j]) {
        Exit();
      }
    }
  }
  cout<<ans<<endl;
  RE (i, n) {
    debug(i, row[i]);
    REP (x, row[i]) {
      if (sw == 0) {
        cout<<"row ";
      } else {
        cout<<"col ";
      }
      cout<<i<<"\n";
    }
  }
  RE (i, m) {
    debug(i, col[i]);
    REP (x, col[i]) {
      if (sw == 1) {
        cout<<"row ";
      } else {
        cout<<"col ";
      }
      cout<<i<<"\n";
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}