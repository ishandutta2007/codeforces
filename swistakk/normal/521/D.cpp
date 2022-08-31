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
const int N = 1e5 + 5;
vector<PII> imp[N][3];
int init[N];
int beg[N];
vector<Triple<int, int, int>> ways[N];
vector<LD> dp[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make3(int, skills, imp_num, can);
  RE (i, skills) {
    cin>>init[i];
  }
  RE (i, imp_num) {
    make3(int, typ, sk, b);
    typ--;
    if (typ == 2 && b == 1) { continue; }
    imp[sk][typ].PB(MP(b, i));
  }
  RE (i, skills) {
    int sum = 0;
    REP (tr, 3) {
      sort(ALL(imp[i][tr]), greater<PII>());
    }
    imp[i][0].resize(min(1ll, SZ(imp[i][0])));
    REP (tr, 3) {
      sum += SZ(imp[i][tr]);
    }
    imp[i][1].insert(imp[i][1].begin(), MP(0, 0));
    FOR (s, 1, SZ(imp[i][1]) - 1) {
      imp[i][1][s].st += imp[i][1][s - 1].st;
    }
    
    dp[i].resize(sum + 1);
    ways[i].resize(sum + 1);
    vector<LD> logs(SZ(imp[i][2]) + 1);
    FOR (s, 1, SZ(imp[i][2])) {
      logs[s] = logs[s - 1] + log(imp[i][2][s - 1].st);
    }
    FOR (used_ass, 0, 1) {
      int val = init[i];
      if (used_ass && SZ(imp[i][0]) == 0) { continue; }
      if (used_ass && SZ(imp[i][0])) {
        val = imp[i][0][0].st;
      }
      int joined = SZ(imp[i][1]) + SZ(imp[i][2]) - 1;
      FOR (j, 0, joined) {
        int max_mul = min(j, SZ(imp[i][2]));
        FOR (muls, max(0ll, max_mul - 1), max_mul) {
          int adds = j - muls;
          if (adds >= SZ(imp[i][1])) { continue; }
          int st_val = val + imp[i][1][adds].st;
          LD st_log = log(st_val) - log(init[i]);
          LD summed_log = st_log + logs[muls];
          int all = j + used_ass;
          if (summed_log > dp[i][all]) {
            dp[i][all] = summed_log;
            ways[i][all] = {used_ass, adds, muls};
          }
        }
      }
    }
  }
  
  priority_queue<pair<LD, int>> up;
  RE (i, skills) {
    if (SZ(dp[i]) >= 2) {
      up.push(MP(dp[i][1], i));
      
    }
    beg[i] = 1;
  }
  int ops = 0;
  RE (its, can) {
    if (up.empty()) { 
      break;
    }
    auto p = up.top();
    debug(p.st);
    if (p.st < 1e-15) { break; }
    int w_sk = p.nd;
    beg[w_sk]++;
    up.pop();
    if (SZ(dp[w_sk]) > beg[w_sk]) {
      up.push(MP(dp[w_sk][beg[w_sk]] - dp[w_sk][beg[w_sk] - 1], w_sk));
    }
    ops++;
  }
  cout<<ops<<"\n";
  int cnt_tmp = 0;
  RE (i, skills) {
    auto trip = ways[i][beg[i] - 1];
    if (trip.st) {
      cout<<imp[i][0][0].nd<<" ";
    }
    RE (j, trip.nd) {
        cout<<imp[i][1][j].nd<<" ";
    }
    REP (j, trip.rd) {
        cout<<imp[i][2][j].nd<<" ";
    }
  }
  cout<<"\n";
  
  
  
  
  
  
  
  
  
  return 0;
}