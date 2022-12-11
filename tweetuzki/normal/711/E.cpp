#include <cstdio>

const int Mod = 1000003;

long long N, K;

inline int add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inline int sub(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }
inline int mul(int x, int y) { return 1LL * x * y % Mod; }
inline int pw(int x, long long y) { int z = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) z = mul(z, x); return z; }
inline int inv(int x) { return pw(x, Mod - 2); }
inline int sep(int x, int y) { return mul(x, inv(y)); }

inline bool k_gr_2_n() {
  long long res = 1;
  for (long long i = 1; i <= N; ++i) {
    res <<= 1;
    if (res >= K) return false;
  }
  return true;
}

inline int lowBit(long long x) {
  int res = 0;
  while (x % 2 == 0) {
    res++;
    x >>= 1;
  }
  return res;
}

inline int countBit(long long x) {
  int res = 0;
  while (x) {
    res++;
    x -= (x & -x);
  }
  return res;
}

int main() {
  scanf("%lld %lld", &N, &K);
  if (k_gr_2_n()) {
    puts("1 1");
    return 0;
  }
  if (K < Mod) {
    long long res = 1LL * (N % (Mod - 1)) * ((K - 1) % (Mod - 1)) % (Mod - 1);
    int fz = 1;
    for (long long i = 1; i <= K - 1; ++i) {
      int a = lowBit(i);
      res -= a;
      fz = mul(fz, sub(pw(2, N - a), (i / (1LL << a)) % Mod));
    }
    res = ((res % (Mod - 1)) + (Mod - 1)) % (Mod - 1);
    printf("%d %d\n", sub(pw(2, res), fz), pw(2, res));
  } else {
    long long res = 1LL * (N % (Mod - 1)) * ((K - 1) % (Mod - 1)) % (Mod - 1);
    res -= (K - 1) - countBit(K - 1);
    res = (res % (Mod - 1) + (Mod - 1)) % (Mod - 1);
    printf("%d %d\n", pw(2, res), pw(2, res));
  }
  return 0;
}