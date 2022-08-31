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


const LD kPi = 2 * acos(0);

struct CD {
  LD re, im;
  CD operator=(LD a) { re = a; im = 0; return *this; }
  CD operator*(CD &z) { return {re * z.re - im * z.im, re * z.im + im * z.re}; }
  void operator*=(CD &z) { *this = (*this * z); }
  CD operator+(CD &z) { return {re + z.re, im + z.im}; }
  CD operator-(CD &z) { return {re - z.re, im - z.im}; }
  void operator/=(LD f) { re /= f; im /= f; }
};

struct FFT {
  CD *A, *B, *tmp, *res, *omega;
  int *rev_perm;
  int max_dep;
  
  void Clear(int n) {
    REP (i, n) { A[i] = B[i] = res[i] = tmp[i] = 0; }
  }
  
  void fft(CD *from, CD *to, int depth, bool inv) {
    int N = (1 << depth);
    REP (i, N) { to[rev_perm[i] >> (max_dep - depth)] = from[i]; }
    
    RE (m, depth) {
      int step = (1 << m);
      for (int pos = 0; pos < N; pos += step) {
        int cur = 0;
        int delta = (1 << (max_dep - m));
        if (!inv) { cur = (1 << max_dep); delta *= -1; }
        REP (k, step / 2) {
          CD a = to[pos + k],
             b = omega[cur] * to[pos + k + step / 2];
          to[pos + k] = a + b;
          to[pos + k + step / 2] = a - b;
          cur += delta;
        }
      }
    }
    
    if (inv) { REP (i, N) { to[i] /= N; } }
  }
  
  FFT(int max_deg) {
    max_dep = 0;
    while ((1 << max_dep) <= 2 * max_deg) { max_dep++; }
    max_deg = (1 << max_dep) + 20;
    
    A = new CD[max_deg];
    B = new CD[max_deg];
    res = new CD[max_deg];
    tmp = new CD[max_deg];
    omega = new CD[max_deg];
    rev_perm = new int[max_deg];
    
    int N = (1 << max_dep);
    LD ang = 2 * kPi / N;
    REP (i, N + 1) { omega[i] = {cos(i * ang), sin(i * ang)}; }
    rev_perm[0] = 0;
    int h = -1;
    
    RE (i, N) {
      if ((i & (i - 1)) == 0) { h++; }
      rev_perm[i] = rev_perm[i ^ (1 << h)] | (1 << (max_dep - h - 1));
    }
  }
  
  VI mul_less_exact(VI &Q, VI &R, bool same) {
    int depth = 0, size = 1;
    int N = SZ(Q) + SZ(R) - 1;
    while (size < N) { depth++; size *= 2; }
    
    Clear(size);
    
    REP (i, SZ(Q)) { A[i] = Q[i]; }
    REP (i, SZ(R)) { B[i] = R[i]; }
    fft(A, res, depth, false);
    if (!same) {
      fft(B, tmp, depth, false);
    } else {
      REP (i, size) {
        tmp[i] = res[i];
      }
    }
    REP (i, size) tmp[i] *= res[i];
    
    fft(tmp, res, depth, true);
    VI ans;
    REP (i, N) { ans.PB((long long)round(res[i].re)); }
    return ans;
  }
};


string Nstr;
vector<int> N;
int len;

// vector<int> divX1(vector<int> V) {
//   int S = SZ(V);
//   vector<int> res(S - 1);
//   for (int i = S - 1; i > 0; i--) {
//     res[i - 1] = V[i];
//     V[i - 1] -= V[i];
//   }
//   debug(res);
//   assert(V[0] == 0);
//   return res;
// }

vector<int> result;

const int MaxDeg = 4e5;
const int B = 10000;
FFT fft(MaxDeg + 5555);

vector<int> Mnoz(vector<int> zium, int dig) {
  vector<int> res(SZ(zium) + 5);
  zium.PB(0);
  int carry = 0;
  REP (i, SZ(zium)) {
    int huh = carry + zium[i] * dig;
    carry = huh / B;
    res[i] = huh % B;
  }
  while (res.back() == 0) {
    res.pop_back();
  }
  return res;
}

bool Cmp(VI L, VI R) {
  if (SZ(L) != SZ(R)) {
    return SZ(L) < SZ(R);
  }
  FORD (i, SZ(L) - 1, 0) {
    if (L[i] != R[i]) {
      return L[i] < R[i];
    }
  }
  return true;
}

vector<int> MnozBig(VI& a, VI& b, int same) {
//   int lol = SZ(a) + SZ(b) + 5;
//   FFT fftt(lol);
  VI res = fft.mul_less_exact(a, b, same);
  res.PB(0);
  res.PB(0);
  REP (i, SZ(res) - 2) {
    res[i + 1] += res[i] / B;
    res[i] %= B;
  }
  while (res.back() == 0) {
    res.pop_back();
  }
  return res;
}

vector<int> Potuj(VI a, int b) {
  VI r{1};
  while (b) {
    if (b % 2) {
      r = MnozBig(r, a, 0);
    }
    b /= 2;
    if (b) {
      a = MnozBig(a, a, 1);
    }
  }
  return r;
}


int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
//   vector<int> dupa{7, 8, 9};
//   debug(Mnoz(dupa, 4));
  
  string Nstr;
  vector<int> N;
  int len;
  cin >> Nstr;
  if (Nstr == "1") {
    cout<<"1\n";
    return 0;
  }
  len = SZ(Nstr);
  reverse(ALL(Nstr));
  for (int i = 0; i < len; i++) {
    N.push_back(Nstr[i] - '0');
  }
  while (SZ(N) % 4) {
    N.PB(0);
  }
  vector<int> compr;
  REP (i, SZ(N) / 4) {
    int b = 4 * i;
    compr.PB(N[b] + 10 * N[b + 1] + 100 * N[b + 2] + 1000 * N[b + 3]);
  }
  //debug(compr);
  N = compr;
  
  LD ziom = 0;
  for (auto x : N) {
    ziom /= B;
    ziom += x;
  }
  LD L = /*log(ziom) +*/ (len - 1) * log(10);
  int zium = max(0ll, (int)(L / log(3) - 1));
  vector<int> pot{3};
  pot = Potuj(pot, zium);
  int best = 1e9;
  int acc = 3 * zium;
  debug(zium, acc);
  while (1) {
    if (Cmp(N, pot)) {
      mini(best, acc);
      break;
    }
    vector<int> lo = Mnoz(pot, 2);
    if (Cmp(N, lo)) {
      mini(best, acc + 2);
    } else {
      lo = Mnoz(lo, 2);
      if (Cmp(N, lo)) {
        mini(best, acc + 4);
      }
    }
    pot = Mnoz(pot, 3);
    acc += 3;
  }
  cout<<best<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}