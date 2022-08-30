#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define LL long long
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

const int mod = 998244353;
const int p = mod;
const int gen = 5;

int powMod(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) { res = ((LL)res * a) % p; }
    n >>= 1; a = ((LL)a * a) % p;
  }
  return res;
}


struct FFT {
private:
  int *A, *B, *tmp, *res, *omega;
  int *perm;
  int maxh;
  // not needed if this is going to be used just once
  void Clear(int n) {
    REP (i, n) { A[i] = B[i] = res[i] = tmp[i] = 0; }
  }
  
  void fft(int* from, int* to, int depth, bool inv){
    int N = (1 << depth);
    for (int i = 0; i < N; i++) { to[perm[i] >> (maxh - depth)] = from[i]; }
    RE (m, depth) {
      int step = 1 << m;
      for (int pos = 0; pos < N; pos += step){
        int cur = 0;
        int delta = 1 << (maxh - m);
        if (!inv) { cur = 1 << maxh; delta *= -1; }
        int *lft = to + pos, *rgt = lft + step / 2;
        REP (k, step / 2) {
          int a = *lft, b = (ll)omega[cur] * *rgt % mod;
          *lft = a + b; if (*lft >= mod) { *lft -= mod; } ++lft;
          *rgt = a - b; if (*rgt < 0) { *rgt += mod; } ++rgt;
          cur += delta;
        }
      }
    }
    
    if (inv) {
      const int a = powMod(N, mod - 2);
      REP (i, N) { to[i] = (ll)to[i] * a % mod; }
    }
  }
  
public:
  FFT(int deg) { // max degree of a polynomial given as input
    maxh = 0; int N = 1, h = -1;
    while (N <= 2 * deg) { maxh++; N *= 2; }
    deg = N + 20;
    A = new int[deg];
    B = new int[deg];
    res = new int[deg];
    tmp = new int[deg];
    omega = new int[deg];
    perm = new int[deg];
    
    omega[0] = 1;
    omega[1] = powMod(gen, (p - 1) / N);
    for (int i = 2; i <= N; ++i) {
      omega[i] = (ll)omega[i - 1] * omega[1] % mod;
    }
    perm[0] = 0;
    RE (i, N - 1) {
      if ((i & (i - 1)) == 0) { h++; }
      perm[i] = perm[i ^ (1 << h)] | (1 << (maxh - h - 1));
    }
  }
  /*VI pow(VI Q, int x, int terms) {
   *   int depth = 0, size = 1;
   *   int N = terms + 5;
   *   while (size < N) { depth++; size *= 2; }
   *   Clear(size);
   *   copy(ALL(Q), A);// copy(ALL(R), B);
   *   fft(A, res, depth, false);
   *   REP (i, size) tmp[i] = powMod(res[i], x);
   *   // koniec
   *   fft(tmp, res, depth, true);
   *   VI ans;
   *   REP (i, terms) { ans.PB(res[i]); }
   *   return ans;
}*/
  VI mul(VI Q, VI R) {
    int depth = 0, size = 1;
    int N = SZ(Q) + SZ(R) - 1;
    while (size < N) { depth++; size *= 2; }
    Clear(size);
    copy(ALL(Q), A); copy(ALL(R), B);
    fft(A, res, depth, false);
    if (Q == R) {
      REP (i, size) tmp[i] = (ll)res[i] * res[i] % mod;
    } else {
      fft(B, tmp, depth, false);
      REP (i, size) tmp[i] = (ll)tmp[i] * res[i] % mod;
    }
    fft(tmp, res, depth, true);
    VI ans;
    REP (i, N) { ans.PB(res[i]); }
    return ans;
  }
};

FFT fft((int)2e4 + 5);

VI Rec(VI& B, int L, int R, int k) {
  if (L == R) {
    return {1, B[L]};
  }
  int M = (L + R) / 2;
  VI lewo = Rec(B, L, M, k);
  VI prawo = Rec(B, M + 1, R, k);
  VI res = fft.mul(lewo, prawo);
  if (SZ(res) > k + 1) {
    res.resize(k + 1);
  }
  return res;
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  

  int n, k;
  cin>>n>>k;
  VI a(n);
  REP (i, n) {
    cin>>a[i];
  }
  int q;
  cin>>q;
  RE (qq, q) {
    int t, x;
    cin>>t>>x;
    VI B;
    if (t == 1) {
      int i, d;
      cin>>i>>d;
      B = a;
      B[i - 1] = d;
    } else {
      int L, R, d;
      cin>>L>>R>>d;
      L--;
      R--;
      B = a;
      FOR (i, L, R) {
        B[i] += d;
      }
    }
    REP (i, SZ(B)) {
      B[i] = x - B[i];
      B[i] = (B[i] % mod + mod) % mod;
    }
    cout<<Rec(B, 0, SZ(B) - 1, k)[k]<<"\n";
  }
        

  
  return 0;
}