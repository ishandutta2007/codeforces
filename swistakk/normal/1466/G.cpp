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
int inv(int a, int P) {
  int r = 1;
  int b = P - 2;
  while (b) {
    if (b % 2) {
      r = r * a % P;
    }
    a = a * a % P;
    b /= 2;
  }
  return r;
}
const int B[2] = {1235, 682637};
const int P[2] = {999999197, 1000000483};
int I[2] = {inv(B[0], P[0]), inv(B[1], P[1])};
typedef array<int32_t, 2> H;
struct Hash {
  int n;
  vector<H> pref;
  vector<H> inv_pow;
  Hash(string s) {
    n = SZ(s);
    s = "$" + s;
    pref.resize(n + 2);
    inv_pow.resize(n + 2);
    //ResizeVec(pref, {n + 2, 2});
    //ResizeVec(inv_pow, {n + 2, 2});
    inv_pow[0][0] = inv_pow[0][1] = 1;
    VI poww(2, 1);
    RE (i, n) {
      REP (tr, 2) {
        inv_pow[i][tr] = 1ll * inv_pow[i - 1][tr] * I[tr] % P[tr];
        pref[i][tr] = (pref[i - 1][tr] + 1ll * s[i] * poww[tr]) % P[tr];
        poww[tr] = 1ll * poww[tr] * B[tr] % P[tr];
      }
    }
  };
  H GetHash(int a, int b) {
    if (a > b) {
      return {0, 0};
    }
    H res;
    REP (tr, 2) {
      int h = (pref[b][tr] - pref[a - 1][tr] + P[tr]) % P[tr];
      res[tr] = 1ll * h * inv_pow[a - 1][tr] % P[tr];
    }
    return res;
  }
};

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  debug(I[0] * B[0] % P[0]);
  debug(I[1] * B[1] % P[1]);
  
  
  int n, q;
  cin>>n>>q;
  string s0, t;
  cin>>s0>>t;
  t = "$" + t;
  vector<string> songs(n + 2);
  songs[0] = s0;
  RE (i, n) {
    songs[i] = songs[i - 1] + string(1, t[i]) + songs[i - 1];
    if (SZ(songs[i]) >= (int)1e6 + 5) {
      break;
    }
  }
  vector<Hash> hashes;
  REP (i, n + 1) {
    if (!songs[i].empty()) {
      hashes.PB(Hash(songs[i]));
    }
  }
  const int M = 1e9 + 7;
  int i2 = (M + 1) / 2;
  VVI cnt_t(n + 2, VI(28));
  VI pow2(n + 2);
  pow2[0] = 1;
  int pi2 = 1;
  RE (i, n) {
    pi2 = pi2 * i2 % M;
    pow2[i] = pow2[i - 1] * 2 % M;
    cnt_t[i] = cnt_t[i - 1];
    cnt_t[i][t[i] - 'a'] = (cnt_t[i][t[i] - 'a'] + pi2) % M;
  }
  RE (_, q) {
    int k;
    string sailor;
    cin>>k>>sailor;
    int from = 0;
    while (SZ(songs[from]) < SZ(sailor)) {
      from++;
    }
    if (from > k) {
      cout<<"0\n";
      continue;
    }
    int T = SZ(sailor);
    int S = SZ(songs[from]);
    int full = 0;
    Hash sailor_hash(sailor);
    H full_hash = sailor_hash.GetHash(1, T);
    RE (i, S - T + 1) {
      if (hashes[from].GetHash(i, i + T - 1) == full_hash) {
        full++;
      }
    }
    int res = full * pow2[k - from] % M;
    debug(full, res);
    FOR (on_left, 0, T - 1) {
      int on_right = T - on_left - 1;
      //debug(songs[from].substr(S - on_left, on_left), sailor.substr(0, on_left));
      //debug(songs[from].substr(0, on_right), sailor.substr(T - on_right, on_right)); 
      if (hashes[from].GetHash(S - on_left + 1, S) == sailor_hash.GetHash(1, on_left) &&
          hashes[from].GetHash(1, on_right) == sailor_hash.GetHash(T - on_right + 1, T)) {
        debug(on_left);
        debug(cnt_t[k][sailor[on_left] - 'a'] * pow2[k]);
        res = (res + (cnt_t[k][sailor[on_left] - 'a'] - cnt_t[from][sailor[on_left] - 'a'] + M) * pow2[k]) % M;
      }
    }
    cout<<res<<"\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}