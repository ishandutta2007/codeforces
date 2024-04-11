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
typedef long long LL;
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

const int N = 55;
int dp[N][N];
    
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int t;
  cin>>t;
  if (t <= 40) {
    cout<<2<<" "<<t<<endl<<"0\n";
    return 0;
  }
  int n = 5;
  vector<pair<PII, PII>> walls;
  walls.PB({{4, 5}, {5, 5}});
  walls.PB({{5, 4}, {5, 5}});
//   walls.PB({{1, 2}, {2, 2}});
//   FOR (i, 3, 5) {
//     walls.PB({{i, 1}, {i, 2}});
//   }
//   FOR (j, 3, 5) {
//     walls.PB({{4, j}, {5, j}});
//   }
  vector<int> digs;
  int T = t;
  while (t) {
    digs.PB(t % 20);
    t /= 20;
  }
  while (SZ(digs)) {
    int d = digs.back();
    n += 3;
    if (n > 8) {
      walls.PB({{n - 2, n - 8}, {n - 2, n - 7}});
      //walls.PB({{n - 6, n - 3}, {n - 5, n - 3}});
      walls.PB({{n - 9, n - 2}, {n - 8, n - 2}});
    }
    FOR (i, n - 1, n) {
      walls.PB({{i, n - 5}, {i, n - 4}});
    }
    FOR (j, n - 6, n - 4) {
      walls.PB({{n - 3, j}, {n - 2, j}});
    }
    FOR (i, n - 6 - (n > 8), n - 4) {
      walls.PB({{i, n - 3}, {i, n - 2}});
    }
    walls.PB({{n - 5, n - 1}, {n - 4, n - 1}});
    walls.PB({{n - 6, n - 1}, {n - 5, n - 1}});
    walls.PB({{n - 6, n}, {n - 5, n}});
    if (d >= 10) {
      d -= 10;
    } else {
      walls.PB({{n - 2, n - 4}, {n - 2, n - 3}});
    }
    walls.PB({{n - 4, n - 2}, {n - 3, n - 2}});
    if (d >= 4) {
      d -= 4;
    } else {
      walls.PB({{n - 1, n - 4}, {n - 1, n - 3}});
    }
    if (d >= 4) {
      d -= 4;
    } else {
      walls.PB({{n - 4, n - 1}, {n - 3, n - 1}});
    }
    if (d >= 2) {
      d -= 2;
    } else {
      walls.PB({{n - 4, n}, {n - 3, n}});
    }
    if (d >= 1) {
      d -= 1;
    } else {
      walls.PB({{n, n - 4}, {n, n - 3}});
    }
    digs.pop_back();
  }
  cout<<n<<" "<<n<<endl;
  assert(SZ(walls) <= 300);
  cout<<SZ(walls)<<endl;
  set<pair<PII, PII>> forb;
  for (auto x : walls) {
    forb.insert(x);
    cout<<x.st.st<<" "<<x.st.nd<<" "<<x.nd.st<<" "<<x.nd.nd<<"\n";
  }
  assert(SZ(walls) == SZ(forb));
  dp[1][1] = 1;
  RE (i, n) {
    RE (j, n) {
      if (!forb.count({{i - 1, j}, {i, j}})) {
        dp[i][j] += dp[i - 1][j];
      }
      if (!forb.count({{i, j - 1}, {i, j}})) {
        dp[i][j] += dp[i][j - 1];
      }
    }
  }
//   RE (i, n) {
//     cout<<".";
//     RE (j, n) {
//       if (forb.count({{i - 1, j}, {i, j}})) {
//         cout<<"-";
//       } else {
//         cout<<" ";
//       }
//       cout<<".";
//     }
//     cout<<endl<<"|";
//     RE (j, n) {
//       cout<<" ";
//       if (forb.count({{i, j}, {i, j + 1}})) {
//         cout<<"|";
//         //dp[i][j] += dp[i][j - 1];
//       } else {
//         cout<<" ";
//       }
//     }
//     cout<<endl;
//   }
      
  debug(dp[n][n], T);
      
  
  
    
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}