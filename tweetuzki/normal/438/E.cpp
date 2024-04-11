#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 100000 + 5, MaxV = 800000 + 5;
const int Mod = 998244353, Ptr = 3;
const int MaxLog = 20 + 5;

int M, V;
int A[MaxV];
int Rev[MaxLog][MaxV], Log[MaxV];

inline int add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inline int sub(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }
inline int mul(int x, int y) { return 1LL * x * y % Mod; }
inline int pw(int x, int y) { int z = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) z = mul(z, x); return z; }
inline int inv(int x) { return pw(x, Mod - 2); }
inline int sep(int x, int y) { return mul(x, inv(y)); }

void init() {
  int n;
  scanf("%d %d", &n, &M);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    A[x] = 1;
  }
  V = 131072;
  for (int i = 2; i < MaxV; ++i) Log[i] = Log[i >> 1] + 1;
}

inline void ntt(int *a, int n, int f) {
  if (Rev[Log[n]][1] == 0) {
    for (int i = 1; i < n; ++i) {
      Rev[Log[n]][i] = Rev[Log[n]][i >> 1] >> 1;
      if (i & 1) Rev[Log[n]][i] |= (n >> 1);
    }
  }
  for (int i = 1; i < n; ++i)
    if (i < Rev[Log[n]][i]) std::swap(a[i], a[Rev[Log[n]][i]]);
  for (int i = 1; i < n; i <<= 1) {
    int w = pw(pw(Ptr, f), (Mod - 1) / (i << 1));
    for (int j = 0; j < n; j += (i << 1)) {
      int x = 1;
      for (int k = 0; k < i; ++k, x = mul(x, w)) {
        int ls = a[j + k], rs = a[i + j + k];
        a[j + k] = add(ls, mul(rs, x));
        a[i + j + k] = sub(ls, mul(rs, x));
      }
    }
  }
  if (f == Mod - 2) {
    int invN = inv(n);
    for (int i = 0; i < n; ++i) a[i] = mul(a[i], invN);
  }
}

void polyInv(int *a, int *b, int n) {
  if (n == 1) {
    b[0] = inv(a[0]);
    return;
  }
  polyInv(a, b, n >> 1);
  static int c[MaxV], d[MaxV];
  for (int i = 0; i < n; ++i) c[i] = a[i], d[i] = b[i];
  for (int i = n; i < n + n; ++i) c[i] = d[i] = 0;
  ntt(c, n + n, 1); ntt(d, n + n, 1);
  for (int i = 0; i < n + n; ++i)
    b[i] = mul(d[i], sub(2, mul(c[i], d[i])));
  ntt(b, n + n, Mod - 2);
  for (int i = n; i < n + n; ++i) b[i] = 0;
}

void polySqrt(int *a, int *b, int n) {
  if (n == 1) {
    b[0] = 1;
    return;
  }
  polySqrt(a, b, n >> 1);
  static int c[MaxV], d[MaxV];
  polyInv(b, d, n);
  for (int i = 0; i < n; ++i) c[i] = a[i];
  for (int i = n; i < n + n; ++i) c[i] = d[i] = 0;
  ntt(c, n + n, 1); ntt(d, n + n, 1);
  for (int i = 0; i < n + n; ++i) c[i] = mul(c[i], d[i]);
  ntt(c, n + n, Mod - 2);
  for (int i = 0; i < n; ++i) b[i] = mul(add(b[i], c[i]), (Mod + 1) >> 1);
}

void solve() {
  static int b[MaxV], c[MaxV];
  for (int i = 0; i < V; ++i) A[i] = sub(i == 0, mul(4, A[i]));
  polySqrt(A, b, V);
  b[0] = add(b[0], 1);
  polyInv(b, c, V);
  for (int i = 0; i < V; ++i) c[i] = mul(c[i], 2);
  for (int i = 1; i <= M; ++i) printf("%d\n", c[i]);
}

int main() {
  init();
  solve();
  return 0;
}