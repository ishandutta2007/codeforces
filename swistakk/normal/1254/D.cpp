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

const int P = 998244353;
const int N = 2e5;
const int M = 1 << 18;
const int kThres = 600;
int drz[2 * M + 5];
int is_big[N];
int acc[N];
VI slo[N];
int spow(int a, int b) {
  int r = 1;
  while (b) {
    if (b % 2) {
      r = r * a  % P;
    }
    a = a * a % P;
    b /= 2;
  }
  return r;
}
int Inv(int a) { return spow(a, P - 2); }
void Add(int a, int b, int val) {
  a += M - 1;
  b += M - 1;
  drz[a] = (drz[a] + val) % P;
  if (a != b) {
    drz[b] = (drz[b] + val) % P;
  }
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      drz[a + 1] = (drz[a + 1] + val) % P;
    }
    if (b % 2 == 1) {
      drz[b - 1] = (drz[b - 1] + val) % P;
    }
    a /= 2;
    b /= 2;
  }
}
int Read(int a) {
  a += M - 1;
  int sum = 0;
  while (a) {
    sum = (sum + drz[a]) % P;
    a /= 2;
  }
  return sum;
}
int pre[N];
int dd;
int sz[N];
int par[N];
int IsAncOf(int v, int u) {
  return pre[v] <= pre[u] && pre[u] + sz[u] <= pre[v] + sz[v];
}
void Dfs(int v, int p) {
  par[v] = p;
  dd++;
  sz[v] = 1;
  pre[v] = dd;
  for (auto& nei : slo[v]) {
    if (nei == slo[v].back() && v != 1) {
      assert(nei == p);
      break;
    }
    if (nei == p) {
      swap(nei, slo[v].back());
    }
    Dfs(nei, v);
    sz[v] += sz[nei];
  }
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, q;
  cin>>n>>q;
  int invn = Inv(n);
  RE (i, n - 1) {
    int a, b;
    cin>>a>>b;
    slo[a].PB(b);
    slo[b].PB(a);
  }
  VI bigs;
  RE (i, n) {
    if (SZ(slo[i]) > kThres) {
      is_big[i] = 1;
      bigs.PB(i);
    }
  }
  Dfs(1, -1);
  RE (i, q) {
    int t, v;
    cin>>t>>v;
    if (t == 2) {
      int res = Read(pre[v]);
      for (auto big : bigs) {
        if (big == v) {
          res = (res + acc[big]) % P;
        } else if (IsAncOf(big, v)) {
          int kl = 0, kp = SZ(slo[big]) - 1 - (big != 1);
          int faj = -1;
          while (kl <= kp) {
            int aktc = (kl + kp) / 2;
            if (pre[slo[big][aktc]] <= pre[v]) {
              faj = aktc;
              kl = aktc + 1;
            } else {
              kp = aktc - 1;
            }
          }
          assert(faj != -1);
          int son = slo[big][faj];
          //debug(big, v, son);
          res = (res + acc[big] * (n - sz[son]) % P * invn) % P;
        } else {
          int outside_val = sz[big] * invn % P * acc[big] % P;
          res = (res + outside_val) % P;
        }
        //debug(big, v, res);
      }
      cout<<res<<"\n";
    } else {
      int d;
      cin>>d;
      if (is_big[v]) {
        acc[v] = (acc[v] + d) % P;
      } else {
        for (auto ch : slo[v]) {
          if (ch == par[v]) { continue; }
          int val = (n - sz[ch]) * invn % P * d % P;
          Add(pre[ch], pre[ch] + sz[ch] - 1, val);
        }
        int outside_val = sz[v] * invn % P * d % P;
        Add(pre[v], pre[v], d);
        if (pre[v] > 1) {
          Add(1, pre[v] - 1, outside_val);
        }
        if (pre[v] + sz[v] <= n) {
          Add(pre[v] + sz[v], n, outside_val);
        }
      }
    }
  }
  
  
  
  return 0;
}