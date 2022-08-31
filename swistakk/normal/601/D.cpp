#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
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
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
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

const int P = 1e9 + 33;
const int N = 3e5 + 5;
const int X = 2;
set<PII> hashes[N];
VI slo[N];
int vis[N];
int best_val;
int cnt_best;
int pots[N];
int spow(int a, int b) {
  int r = 1;
  while (b) {
    if (b % 2) {
      r = 1ll * r * a  % P;
    }
    a = 1ll * a * a % P;
    b /= 2;
  }
  return r;
}
int Inv(int a) {
  return spow(a, P - 2);
}
int trans[N][2];
int mult[N][2];
int let[N];
int inv_mult[N][2];
// real_hash[v] = hashes[v] * mult + trans
int FromAToB(int a, int b, int h, int x) {
  int r1 = (1ll * h * mult[a][x] + trans[a][x]) % P;
  int r2 = 1ll * (r1 - trans[b][x] + P) * inv_mult[b][x] % P;
  return r2;
}
int c[N];
int bon[2];
void Dfs(int v) {
  vis[v] = 1;
  hashes[v].insert({let[v], let[v]});
  mult[v][0] = mult[v][1] = 1;
  inv_mult[v][0] = inv_mult[v][1] = 1;
  for (auto nei : slo[v]) {
    if (vis[nei]) { continue; }
    Dfs(nei);
    REP (tr, 2) {
      trans[nei][tr] = (1ll * bon[tr] * trans[nei][tr] + let[v]) % P;
      mult[nei][tr] = 1ll * mult[nei][tr] * bon[tr] % P;
      inv_mult[nei][tr] = Inv(mult[nei][tr]);
    }
    int a = v;
    int b = nei;
    if (SZ(hashes[a]) < SZ(hashes[b])) {
      swap(a, b);
    }
    for (auto x : hashes[b]) {
      hashes[a].insert({FromAToB(b, a, x.st, 0), FromAToB(b, a, x.nd, 1)});
    }
    if (a == nei) {
      swap(hashes[v], hashes[nei]);
      REP (tr, 2) {
        mult[v][tr] = mult[nei][tr];
        inv_mult[v][tr] = inv_mult[nei][tr];
        trans[v][tr] = trans[nei][tr];
      }
    }
  }
  debugv(hashes[v]);
  
  int cand = SZ(hashes[v]) + c[v];
  debug(v, cand); 
  if (cand > best_val) {
    best_val = cand;
    cnt_best = 1;
  } else if (cand == best_val) {
    cnt_best++;
  }
}
  
    
int main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
//   pots[0] = 1;
//   inv[0] = 1;
//   RE (i, N - 1) {
//     pots[i] = (pots[i - 1] * 2) % P;
//     inv[i] = 1ll * inv[i - 1] * ((P + 1) / 2) % P;
//   }

  bon[0] = 2456;
  bon[1] = 45644;
// #ifdef LOCAL
//   bon = 2;
// #endif
  
  make(int, n);
  RE (i, n) {
    cin>>c[i];
  }
  RE (i, n) {
    make(char, ch);
    let[i] = (int)ch;
#ifdef LOCAL
    let[i] -= (int)('a') - 4;
#endif
  }
  RE (i, n - 1) {
    make2(int, a, b);
    slo[a].PB(b);
    slo[b].PB(a);
  }
  Dfs(1);
  cout<<best_val<<" "<<cnt_best<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}