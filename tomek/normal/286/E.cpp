//{{{
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << endl;

typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
template<class T> inline int size(const T&c) { return c.size(); }
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
string rstring() { static char buf[100000]; if(scanf("%s",buf)!=1) return ""; return buf; }
//}}}

const int PRIME = (11<<21) + 1;
const int N = 1<<21;

int gcd(int a, int b) { return b==0? a : gcd(b, a%b); }
int lcm(int a, int b) { return a/gcd(a,b) * b; }

template<class T>
T power(T a, ULL b) {
  T res = T(1);
  while(b) {
    if(b&1u) res *= a;
    b >>= 1;
    a = a*a;
  }
  return res;
}

template<unsigned MOD>
class Modulo {
  unsigned v;
 public:
  Modulo() {}
  Modulo(unsigned x):v(x%MOD) {}
  int get() const { return v; }
  Modulo operator+(Modulo b) const { return Modulo(v+b.v); }
  void operator+=(Modulo b) { *this = *this + b; }
  Modulo operator-(Modulo b) const { return Modulo(v+MOD-b.v); }
  void operator-=(Modulo b) { *this = *this - b; }
  Modulo operator*(Modulo b) const { return Modulo(unsigned(ULL(v) * ULL(b.v) % MOD)); }
  void operator*=(Modulo b) { *this = *this * b; }
  Modulo operator/(Modulo b) const { return *this * b.inverse(); }
  void operator/=(Modulo b) { *this = *this / b; }
  Modulo inverse() const { return power(*this, MOD-2); }
};

typedef Modulo<PRIME> Mod;

const Mod W = Mod(38);
const Mod W_INV = W.inverse();

void fft(Mod *v, int sh, int n, Mod w) {
  if(n==1) return;
  Mod w2 = w*w;
  int n2 = n/2;
  fft(v, sh+1, n2, w2);
  fft(v+(1<<sh), sh+1, n2, w2);
  static Mod tmp[N];
  Mod wx = 1;
  for(int i=0;i<n2;++i) {
    Mod A = v[i<<(sh+1)];
    Mod B = v[(i<<(sh+1))+(1<<sh)];
    Mod wxB = wx*B;
    tmp[i] = A + wxB;
    tmp[n2+i] = A - wxB;
    wx *= w;
  }
  REP(i,n) v[i<<sh] = tmp[i];
}

vector<int> Square(const vector<int> &v) {
  int m = size(v);
  vector<Mod> x(N, Mod(0));
  REP(i,m) if(v[i]) x[i] = 1;
  fft(&x[0], 0, N, W);
  REP(i,N) x[i] = x[i] * x[i];
  fft(&x[0], 0, N, W_INV);
  vector<int> res(m, 0);
  REP(i, m) if(x[i].get() != 0) res[i]=1;
  return res;
}

int main() {
  int n = rint();
  int m = rint();
  vector<int> poss(m+1, 0);
  REP(i,n) poss[rint()] = 1;
  vector<int> poss2 = Square(poss);
  vector<int> p(m+1,0);
  FOR(i,1,m) {
    if(poss2[i] && !poss[i]) {
      printf("NO\n");
      return 0;
    }
    p[i] = poss[i] && !poss2[i];
  }
  int cnt = 0;
  FOR(i,1,m) if(p[i]) ++cnt;
  printf("YES\n%d\n", cnt);
  FOR(i,1,m) if(p[i]) printf("%d ", i);
  printf("\n");
}