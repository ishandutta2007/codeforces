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
#ifdef LOCAL
#define debug(x) {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, t) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#t <<" = " <<t<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x,y,z,t)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
using namespace std;
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
template<class A, class B, class C> struct Triple { A first; B second; C third; };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}

const int N = 21;
const int INF = 1e9;
int dp[1 << N];
string s[N];
int cost[N][N];
int mincost[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, m);
  REP (i, n) {
    cin>>s[i];
    //s[i] = ' ' + s[i];
  }
  REP (i, n) {
    mincost[i] = INF;
    REP (j, m) {
      cin>>cost[i][j];
      mini(mincost[i], cost[i][j]);
    }
  }
  REP (i, 1 << n) {
    dp[i] = INF;
  }
  dp[0] = 0;
  REP (col, m) {
    for (char c = 'a'; c <= 'z'; c++) {
      int sum = 0;
      int max_here = 0;
      int mask = 0;
      REP (i, n) {
        if (s[i][col] == c) {
          mask += (1 << i);
          sum += cost[i][col];
          maxi(max_here, cost[i][col]);
        }
      }
      if (mask) {
        sum -= max_here;
        debug2(mask, sum);
        REP (ne_m, (1 << n)) {
            mini(dp[ne_m | mask], dp[ne_m] + sum);
            //mini(dp[ne_m], dp[ne_m - mask] + sum);
         
        }
      }
    }
  }
  int best = INF;
  REP (mask, (1 << n)) {
    int cur = dp[mask];
    REP (i, n) {
      if ((mask & (1 << i)) == 0) {
        cur += mincost[i];
      }
    }
    mini(best, cur);
  }
  cout<<best<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}