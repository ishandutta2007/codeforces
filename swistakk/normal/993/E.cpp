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

typedef long long LL;
int powMod(int a, int n, int p) {
  int res = 1;
  while (n) {
    if (n & 1) res = ((LL)res * a) % p;
    n >>= 1;
    a = ((LL)a * a) % p;
  }
  return res;
}

int invMod(int a, int p) { return powMod(a, p - 2, p); }



typedef long double LD;
const LD kPi = 2 * acos(0);
struct CD {
  LD re, im;
  CD operator=(LD a) {
    re = a;
    im = 0;
    return *this;
  }
  CD operator*(CD& z) {
    return {re * z.re - im * z.im, re * z.im + im * z.re};
  }
  void operator*=(CD& z) {
    *this = (*this * z);
  }
  CD operator+(CD& z) {
    return {re + z.re, im + z.im};
  }
  CD operator-(CD& z) {
    return {re - z.re, im - z.im};
  }
  void operator/=(LD f) {
    re /= f;
    im /= f;
  }
};

struct FFT {
private:
  CD* A;
  CD* B;
  CD* tmp;
  CD* res;
  CD* omega;
  int* perm;
  int maxh;
  // not needed if this is going to be used just once
  void Clear(int n) {
    REP (i, n) {
      A[i] = B[i] = res[i] = tmp[i] = 0;
    }
  }

  void fft(CD* from, CD* to, int depth, bool inv){
    int N = (1 << depth);
    for (int i = 0; i < N; i++) {
      to[perm[i] >> (maxh - depth)] = from[i];
    }
    for (int m = 1; m <= depth; m++) {
      int step = 1 << m;
      for (int pos = 0; pos < N; pos += step){
        int cur = 0;
        int delta = 1 << (maxh - m);
        if (!inv) {
          cur = 1 << maxh;
          delta *= -1;
        }
        CD *lft = to + pos, *rgt = lft + step / 2;
        for (int k = 0; k < step / 2; k++) {
          CD a = *lft, b = omega[cur] * *rgt;
          *lft++ = a + b; *rgt++ = a - b;
          cur += delta;
        }
      }
    }

    if (inv) {
      for (int i = 0; i < N; i++) to[i] /= N;
    }
  }
  
public:
  FFT(int deg) { // max degree of a polynomial given as input
    maxh = 0; int N = 1, h = -1;
    while (N <= 2 * deg) { maxh++; N *= 2; }
    deg = N + 20;
    A = new CD[deg];
    B = new CD[deg];
    res = new CD[deg];
    tmp = new CD[deg];
    omega = new CD[deg];
    perm = new int[deg];
    LD ang = 2 * kPi / N;
    REP (i, N + 1) { omega[i] = {cos(i * ang), sin(i * ang)}; }
    perm[0] = 0;
    RE (i, N - 1) {
      if ((i & (i - 1)) == 0) { h++; }
      perm[i] = perm[i ^ (1 << h)] | (1 << (maxh - h - 1));
    }
  }
  VI mul_less_exact(VI Q, VI R, int P = (int)(1e18)) {
    int depth = 0, size = 1;
    int N = SZ(Q) + SZ(R);
    while (size < N) { depth++; size *= 2; }
    Clear(size);
    // start miejsca, w ktorym jak mozna mniejsza dokladnosc, to podmienic na komentarze
    // P,Q \in R[x], A = Q * (1+i)/2 + R * (1-i)/2 -> Re(A^2) = P*Q
    copy(ALL(Q), A); copy(ALL(R), B);
    // REP (i, SZ(Q)) { A[i] = CD{.5 * Q[i], .5 * Q[i]}; }
    // REP (i, SZ(R)) { A[i] = A[i] + CD{.5 * R[i], -.5 * R[i]}; }
    // fft(A, tmp, depth, false);
    // REP (i, size) tmp[i] *= tmp[i];
    fft(A, res, depth, false);
    fft(B, tmp, depth, false);
    REP (i, size) tmp[i] *= res[i];
    // koniec
    fft(tmp, res, depth, true);
    VI ans;
    REP (i, N) { ans.PB((long long)round(res[i].re) % P); }
    return ans;
  }
  
  VI Prepare(VI &v, int base, int bpow) {
    VI ans;
    for (auto& x : v) {
      ans.PB(bpow ? x / base : x % base);
    }
    return ans;
  }
  int Sum(VI& v, int P) { // debug/assert purposes only
    int sum = 0;
    for (auto& x : v) {
      sum = (sum + x) % P;
    }
    return sum;
  }
  VI mul_exact(VI Q, VI R, int P) {
    int base = 32000;
    int pows[] = {1, base, (int)1ll * base * base % P};
    VI ans(SZ(Q) + SZ(R));
    REP (q, 2) {
      VI W = Prepare(Q, base, q);
      REP (r, 2) {
        VI V = Prepare(R, base, r);
        // jezeli bedzie za wolno, to mona policzyc tylko 4 transformaty w przod
        // bo aktualnie dla kazdej z 4 czesci jest ona liczona podwojnie (przyspieszenie * 2/3)
        VI C = mul_less_exact(W, V, P);
        for (int i = 0; i < SZ(C); i++) {
          ans[i] = (ans[i] + (LL)C[i] * pows[q + r]) % P;
        }
      }
    }
    debug(Sum(ans, P), (LL)Sum(Q, P) * Sum(R, P) % P);
    assert(Sum(ans, P) == (LL)Sum(Q, P) * Sum(R, P) % P);
    return ans;
  }
  
  // n log n; tested with sqrt: http://codeforces.com/contest/438/submission/26770942
  VI finv(VI Q, int coefs, int P) {
    Q.resize(coefs);
    VI R(coefs); R[0] = invMod(Q[0], P); assert(Q[0]);
    function<void(int)> getInv = [&](int deg) {
      if (deg == 1) { return; }
      int mid = (deg + 1) / 2;
      getInv(mid);
      auto T = mul_less_exact(VI(Q.begin(), Q.begin() + deg), VI(R.begin(), R.begin() + mid), P);
      for (int i = 0; i < mid; i++) { T[i] = P - T[i + mid]; }
      T = mul_less_exact(VI(R.begin(), R.begin() + mid), VI(T.begin(), T.begin() + mid), P);
      for (int i = mid; i < deg; i++) { R[i] = T[i - mid]; }
    };
    getInv(coefs); return R;
  }

  // log(Q)=R: assert(Q[0] = 1), R[0] = 0, R'(x) = Q'(x) / Q(x)

  VI fsqrt(VI Q, int coefs, int P) {   // n log n, large constant, computes inverse in I
    int Inv2 = (P + 1) / 2; Q.resize(coefs + 1);
    VI R(coefs), I(coefs); R[0] = (int)round(sqrt(Q[0])); I[0] = invMod(Q[0], P);
    function<void(int)> getSqrt = [&](int deg) {
      if (deg == 1) { return; }
      int mid = (deg + 1) / 2;
      getSqrt(mid);
      auto T = mul_less_exact(VI(R.begin(), R.begin() + deg), VI(R.begin(), R.begin() + deg), P);
      T.PB(0);
      for (int i = 0; i < mid; i++) {
        T[i] = (LL)(Q[i + mid] - T[i + mid] + P) * Inv2 % P;
      }
      T = mul_less_exact(VI(T.begin(), T.begin() + mid), VI(R.begin(), R.begin() + mid), P);
      T = mul_less_exact(VI(T.begin(), T.begin() + mid), VI(I.begin(), I.begin() + mid), P);
      for (int i = mid; i < deg; i++) { R[i] = T[i - mid]; }

      T = mul_less_exact(VI(Q.begin(), Q.begin() + deg), VI(I.begin(), I.begin() + mid), P);
      for (int i = 0; i < mid; i++) { T[i] = P - T[i + mid]; }
      T = mul_less_exact(VI(I.begin(), I.begin() + mid), VI(T.begin(), T.begin() + mid), P);
      for (int i = mid; i < deg; i++) { I[i] = T[i - mid]; }
    };
    getSqrt(coefs);
    return R;
  }

  // Tested at https://csacademy.com/contest/round-24/#task/colored-forests
  VI fexp(VI Q, int coefs, int P) {   // n log^2 n
    int sz = coefs; while (!sz || (sz & (sz - 1))) { sz++; }
    Q.resize(sz); assert(!Q[0]); VI R(sz);
    function<void(int, int)> getExp = [&](int minDeg, int maxDeg) {
      if (minDeg == maxDeg - 1) {
        R[minDeg] = minDeg ? (LL)invMod(minDeg, P) * R[minDeg] % P : 1;
        return;
      }
      int mid = (minDeg + maxDeg) / 2;
      getExp(minDeg, mid);
      auto T = mul_less_exact(VI(R.begin() + minDeg, R.begin() + mid),
                              VI(Q.begin(), Q.begin() + (maxDeg - minDeg)), P);
      for (int i = mid; i < maxDeg; i++) { R[i] = (T[i - minDeg] + R[i]) % P; }
      getExp(mid, maxDeg);
    };
    for (int i = 0; i < sz; i++) { Q[i] = ((LL)Q[i] * i) % P; }
    getExp(0, sz);
    return VI(R.begin(), R.begin() + coefs);
  }
};

const int N = 1e6 + 5;
int ans[N];

FFT fft((int)1e5 + 5);

void Rec(vector<int> guys) {
  if (SZ(guys) == 1) {
    if (guys[0] == 1) {
      ans[1]++;
    } else {
      ans[0]++;
    }
    return;
  }
  int m = SZ(guys) / 2;
  vector<int> rec1(guys.begin(), guys.begin() + m);
  vector<int> rec2(guys.begin() + m, guys.end());
  Rec(rec1);
  Rec(rec2);
  vector<int> fir(m + 2);
  vector<int> sec(m + 2);
  int cur = 0;
  FOR (i, m, SZ(guys) - 1) {
    cur += guys[i];
    fir[cur]++;
  }
  cur = 0;
  FORD (i, m - 1, 0) {
    cur += guys[i];
    sec[cur]++;
  }
  debug(fir, sec);
  vector<int> zium = fft.mul_less_exact(fir, sec);
  REP (i, SZ(zium)) {
    if (zium[i] == 0) { continue; }
    ans[i] += zium[i];
  }
}
  


int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, x;
  cin>>n>>x;
  vector<int> guys;
  RE (i, n) {
    int a;
    cin>>a;
    if (a < x) {
      guys.PB(1);
    } else {
      guys.PB(0);
    }
  }
  Rec(guys);
  FOR (i, 0, n) {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  //cout<<Rec(guys)<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}