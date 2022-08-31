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

const int P = 998244353;
const int N = 1e6 + 5;
int spow(int a, int b) {
  int r = 1;
  while (b) {
    if (b % 2) {
      r = r * a % P;
    }
    a = a * a % P;
    b /= 2;
  }
  return r;
}
int K;
int fact[N];
int inv_fact[N];
int Choose(int k) {
  return fact[K] * inv_fact[k] % P * inv_fact[K - k] % P;
}
int newer[N];
void ModujSimple(int& a) {
  if (a >= P) {
    a -= P;
  }
}
int k;
void AddVec(VI& sum, VI& down, int sign) {
  REP (len, k + 1) {
    sum[len + 2] = (sum[len + 2] + sign * down[len]) % P;
  }
}  
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  
  VI ns(2);
  cin>>ns[0]>>ns[1];
  
  cin>>k;
  K = k; 
  fact[0] = 1;
  RE (i, k) {
    fact[i] = i * fact[i - 1] % P;
  }
  inv_fact[k] = spow(fact[k], P - 2);
  FORD (i, k - 1, 0) {
    inv_fact[i] = inv_fact[i + 1] * (i + 1) % P;
  }
  if (k % 2) {
    cout<<0<<endl;
    return 0;
  }
  VVI res(2);
  REP (tr, 2) {
    VI dp(k + 2);
    VVI slo(ns[tr] + 2);
    RE (i, ns[tr] - 1) {
      int a, b;
      cin>>a>>b;
      slo[a].PB(b);
      slo[b].PB(a);
    }
    int n = ns[tr];
    VVI down(n + 1, VI(k + 3));
    VVI up(n + 1, VI(k + 3));
    VVI sum(n + 1, VI(k + 3));
    VVI empty_ziom = down;
    function<VI(VI)> Combine = [&](VI add) {
      //debug(add);
      VI ziom(k + 2);
      ziom[0] = 1;
      for (int cur = 2; cur <= k; cur += 2) {
        for (int step = 2; step <= cur; step += 2) {
          ziom[cur] = (ziom[cur] + ziom[cur - step] * add[step]) % P;
          //ModujSimple(ziom[cur]);
        }
      }
      return ziom;
    };
    function<void(int, int)> Dfs1 = [&](int v, int p) {
      for (auto nei : slo[v]) {
        if (nei == p) { continue; }
        Dfs1(nei, v);
        debug(nei, down[nei]);
        AddVec(sum[v], down[nei], 1);
//         REP (len, k + 1) {
//           sum[v][len + 2] = (sum[v][len + 2] + down[nei][len]) % P;
//         }
      }
      down[v] = Combine(sum[v]);
      //debug(down[v]);
    };
//     RE (root, n) {
//       Dfs1(root, -1);
//       FOR (len, 0, k) {
//         dp[len] = (dp[len] + down[root][len]) % P;
//       }
//       if (root == 1 && tr == 1) {
//         debug(sum[root]);
//       }
//       down = empty_ziom;
//       sum = empty_ziom;
//     }
    function<void(int, int)> Dfs2 = [&](int v, int p) {
      if (p != -1) {
        AddVec(sum[v], up[v], 1);
      }
      
      VI all = Combine(sum[v]);
      REP (len, k + 1) {
        dp[len] = (dp[len] + all[len]) % P;
      }
      for (auto nei : slo[v]) {
        if (nei == p) { continue; }
        AddVec(sum[v], down[nei], P - 1);
        up[nei] = Combine(sum[v]);
        AddVec(sum[v], down[nei], 1);
        Dfs2(nei, v);
      }
    };
    Dfs1(1, -1);
    Dfs2(1, -1);
    debug(dp);
    res[tr] = dp;
  }
  
  int lol = 0;
  FOR (x, 0, k) {
    lol = (lol + res[0][x] * res[1][k - x] % P * Choose(x)) % P;
  }
  cout<<lol<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}