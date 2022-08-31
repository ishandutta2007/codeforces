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

const int N = 77;
int wh[N][3];
int32_t dp[N][N][N][3];
int save_cnt[N][3];
const int kInf = 1e9;
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  string s;
  cin>>s;
  vector<int> input;
  VI cnt(3);
  REP (i, n) {
    char x = s[i];
    if (x == 'V') {
      input.PB(0);
    } else if (x == 'K') {
      input.PB(1);
    } else {
      input.PB(2);
    }
    wh[cnt[input.back()]][input.back()] = i;
    cnt[input.back()]++;
    REP (let, 3) {
      save_cnt[i][let] = cnt[let];
    }
  }
  REP (let, 3) {
    REP (i, cnt[let]) {
      debug(let, i, wh[i][let]);
    }
  }
  
  REP (i, N) {
    REP (j, N) {
      REP (k, N) {
        REP (let, 3) {
          dp[i][j][k][let] = kInf;
        }
      }
    }
  }
  //~ REP (i, N) {
    //~ REP (j, N) {
      //~ REP (
  
  dp[0][0][0][2] = 0;
  FOR (i, 0, cnt[0]) {
    FOR (j, 0, cnt[1]) {
      FOR (k, 0, cnt[2]) {
        int pos = i + j + k;
        int cnt_now[3] = {i, j, k};
        REP (prlet, 3) {
          REP (nxlet, 3) {
            int zium;
            if (nxlet == 0) {
              zium = i;
            } else if (nxlet == 1) {
              zium = j;
            } else {
              zium = k;
            }
            
            int cost = 0;
            REP (oth_let, 3) {
              if (nxlet != oth_let) {
                cost += abs(cnt_now[oth_let] - save_cnt[wh[cnt_now[nxlet]][nxlet]][oth_let]);
              }
            }
            if (MP(prlet, nxlet) != MP(0ll, 1ll)) {
              mini(dp[i + (nxlet == 0)][j + (nxlet == 1)][k + (nxlet == 2)][nxlet], (int32_t)(dp[i][j][k][prlet] + cost));
            }
          }
        }
      }
    }
  }
  FOR (i, 0, cnt[0]) {
    FOR (j, 0, cnt[1]) {
      FOR (k, 0, cnt[2]) {
        REP (let, 3) {
          debug(i, j, k, let, dp[i][j][k][let]);
        }
      }
    }
  }
  
  
  int32_t ans = kInf;
  REP (let, 3) {
    mini(ans, dp[cnt[0]][cnt[1]][cnt[2]][let]);
  }
  //cout<<ans<<endl;
  debug(ans);
  assert(ans % 2 == 0);
  cout<<ans / 2<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}