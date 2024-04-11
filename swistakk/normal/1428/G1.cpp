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


int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int k;
  cin>>k;
  VI pow10(8);
  pow10[0] = 1;
  VI f(6);
  REP (i, 6) {
    cin>>f[i];
    pow10[i + 1] = 10 * pow10[i];
  }
  VPII items;
  REP (i, 6) {
    items.PB({f[i] * pow10[5 - i], i});
  }
  sort(ALL(items));
  debug(items);
  const int M = 1e6 + 5;
  VI dp(M, -(int)1e18);
  dp[0] = 0;
  for (auto item : items) {
    int step = 3 * pow10[item.nd];
    VI drz;
    VI puste;
    int max_steps = 3 * (k - 1);
    int B = -1;
    REP (rem, step) {
      drz.clear();
      for (int j = 0; j * step + rem < M; j++) {
        drz.PB(dp[j * step + rem] - j * f[item.nd]);
      }
      if (B == -1) {
        B = 1;
        while (B <= SZ(drz) + 5) {
          B *= 2;
        }
        puste.resize(B);
      }
      drz.insert(drz.begin(), ALL(puste));
      drz.resize(2 * B + 5);
      FORD (i, B - 1, 1) {
        drz[i] = max(drz[2 * i], drz[2 * i + 1]);
      }
      function<int(int, int)> Read = [&](int a, int b) {
        a += B;
        b += B;
        int res = max(drz[a], drz[b]);
        while (a / 2 != b / 2) {
          if (a % 2 == 0) {
            maxi(res, drz[a + 1]);
          }
          if (b % 2 == 1) {
            maxi(res, drz[b - 1]);
          }
          a /= 2;
          b /= 2;
        }
        return res;
      };
      for (int j = 0; j * step + rem < M; j++) {
        maxi(dp[j * step + rem], Read(max(0ll, j - max_steps), j) + j * f[item.nd]);
      }
    }
//     FORD (i, M - 1, 0) {
//       int ma = 3 * (k - 1);
//       mini(ma, i / step);
//       maxi(dp[i], dp[i - ma * step] + ma * f[item.nd]);
//     }
  }
  int q;
  cin>>q;
  RE (_, q) {
    int sum;
    cin>>sum;
    VI dig(6);
    int best = 0;
    REP (last, sum + 1) {
      int tmp = last;
      int here = 0;
      REP (i, 6) {
        dig[i] = tmp % 10;
        tmp /= 10;
        if (dig[i] % 3 == 0) {
          here += dig[i] / 3 * f[i];
        }
      }
      maxi(best, here + dp[sum - last]);
    }
    cout<<best<<"\n";
  }
    
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}