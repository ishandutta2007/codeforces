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
template<class A, class B, class C> struct Triple { A first; B second; C third; };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}

typedef double LD;
const LD kPi = 2 * acos(0);
struct CD {
  LD re, im;
  CD operator=(LD a) {
    re = a;
    im = 0;
    return *this;
  }
  CD operator*(CD z) {
    return {re * z.re - im * z.im, re * z.im + im * z.re};
  }
  void operator*=(CD z) {
    *this = (*this * z);
  }
  CD operator+(CD z) {
    return {re + z.re, im + z.im};
  }
  CD operator-(CD z) {
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
  int max_dep;
  // not needed if this is going to be used just once
  void Clear(int n) {
    REP (i, n) {
      A[i] = B[i] = res[i] = tmp[i] = 0;
    }
  }
  
  inline unsigned rev_bits(unsigned val, int num_bits){
    unsigned mask = 0x0000FFFF;  // 00000000000000001111111111111111
    val = ((val&mask)<<16) | ((val>>16) & mask);
    mask = 0x00FF00FF;           // 00000000111111110000000011111111
    val = ((val&mask)<<8) | ((val>>8) & mask);
    mask = 0x0F0F0F0F;           // 00001111000011110000111100001111
    val = ((val&mask)<<4) | ((val>>4) & mask);
    mask = 0x33333333;           // 00110011001100110011001100110011
    val = ((val&mask)<<2) | ((val>>2) & mask);
    mask = 0x55555555;           // 01010101010101010101010101010101
    val = ((val&mask)<<1) | ((val>>1) & mask);
    return (val >> (32-num_bits));
  }

  void fft(CD* from, CD* to, int depth, bool inv){
    int N = (1<<depth);
    for (int i = 0; i < N; i++) {
      to[rev_bits(i, depth)] = from[i];
    }
    for (int l = 1; l <= depth; l++) {
      int step = (1<<l);
      for (int pos = 0; pos < N; pos += step){
        int cur = 0;
        int delta = (1 << (max_dep - l));
        if (!inv) {
          cur = (1 << max_dep);
          delta *= -1;
        }
        for (int k = 0; k < step / 2; k++){
          CD a = to[pos + k],
            b = omega[cur] * to[pos + k + step / 2];
          to[pos + k] = a + b;
          to[pos + k + step / 2] = a - b;
          cur += delta;
        }
      }
    }

    if(inv) {
      for (int i = 0; i < N; i++) to[i] /= N;
    }
  }
  
public:
  FFT(int max_deg) { // max degree of a polynomial given as input
    max_dep = 0;
    while ((1 << max_dep) <= 2 * max_deg) {
      max_dep++;
    }
    max_deg = 4 * max_deg + 20;
    A = new CD[max_deg];
    B = new CD[max_deg];
    res = new CD[max_deg];
    tmp = new CD[max_deg];
    omega = new CD[max_deg];    
    int N = (1 << max_dep);
    LD ang = 2 * kPi / N;
    FOR (i, 0, N) {
      omega[i] = {cos(i * ang), sin(i * ang)};
    }
  }
  vector<int> mul_less_exact(vector<int> Q, vector<int> R, int P) {
    int depth = 0, size = 1;
    int N = SZ(Q) + SZ(R);
    while (size < N) { depth++; size *= 2; }
    Clear(size);
    REP (i, SZ(Q)) {
      A[i] = CD{.5 * Q[i], .5 * Q[i]};
    }
    REP (i, SZ(R)) {
      A[i] = A[i] + CD{.5 * R[i], -.5 * R[i]};
    }
    fft(A, tmp, depth, false);
    for(int i = 0; i < size; i++) tmp[i] *= tmp[i];
    fft(tmp, res, depth, true);
    vector<int> ans;
    for (int i = 0; i < N; i++) {
      ans.PB((long long)round(res[i].re) % P);
    }
    return ans;
  }
  
  vector<int> Prepare(vector<int>& v, int base, int b_pow) {
    vector<int> ans;
    for (auto& x : v) {
      if (b_pow) {
        ans.PB(x / base);
      } else {
        ans.PB(x % base);
      }
    }
    return ans;
  }
  vector<int> mul_exact(vector<int> Q, vector<int> R, int P) {
    int base = 32000;
    int pows[] = {1, base, 1ll * base * base % P};
    vector<int> ans(SZ(Q) + SZ(R));
    REP (q, 2) {
      vector<int> W = Prepare(Q, base, q);
      REP (r, 2) {
        vector<int> V = Prepare(R, base, r);
        vector<int> C = mul_less_exact(W, V, P);
        for (int i = 0; i < SZ(C); i++) {
          ans[i] = (ans[i] + 1ll * C[i] * pows[q + r]) % P;
        }
      }
    }
    return ans;
  }
};

const int N = 6e5 + 5;
int s[N];
bool allow[N][4];
int match[N];
int tt[N];
int main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  debug(M_PI);
  make3(int, tex, wz, k);
  vector<char> chars{'A', 'C', 'G', 'T'};
  RE (i, tex) {
    make(char, c);
    REP (tr, 4) {
      if (c == chars[tr]) {
        s[i] = tr;
      }
    }
    cerr<<s[i];
  }
  cerr<<"\n";
  RE (i, wz) {
    make(char, c);
    REP (tr, 4) {
      if (c == chars[tr]) {
        tt[i] = tr;
      }
    }
  }
  REP (tr, 4) {
    int last = -k;
    RE (i, tex) {
      if (s[i] == tr) {
        last = i;
      }
      allow[i][tr] = (i - last <= k);
    }
    last = tex + 2 * k + 2;
    FORD (i, tex, 1) {
      if (s[i] == tr) {
        last = i;
      }
      allow[i][tr] |= (last - i <= k);
    }
  }
  FFT fft(max(tex, wz));
  REP (tr, 4) {
    vector<int> A, B;
    REP (i, tex) {
      A.PB(allow[i + 1][tr]);
    }
    REP (i, wz) {
      B.PB((int)(tt[wz - i] == tr));
    }
    vector<int> C = fft.mul_less_exact(A, B, N + 2);
    REP (i, tex + wz + 4) {
      match[i] += C[i];
    }
  }
  
  int res = 0;
  FOR (i, 0, tex + wz + 4) {
    res += (match[i] == wz);
    cerr<<match[i]<<" ";
  }
  cerr<<"\n";
  cout<<res<<endl;
  return 0;
}