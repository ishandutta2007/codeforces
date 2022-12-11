#include <cstdio>

const int MaxN = 200000 + 5;

int N;
int A[MaxN];
double F[MaxN];

inline double add(double x, double y) { return x + y; }
inline double sub(double x, double y) { return x - y; }
inline double mul(double x, double y) { return x * y; }
inline double sep(double x, double y) { return x / y; }

struct BIT {
  double b[MaxN];

  inline int lowbit(int i) {
    return i & -i;
  }

  inline void update(int x, double v) {
    for (int i = x; i <= N; i += lowbit(i))
      b[i] = add(b[i], v);
  }

  inline double query(int x) {
    double res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
      res = add(res, b[i]);
    return res;
  }

  inline double qrange(int l, int r) {
    return sub(query(r), query(l - 1));
  }
};
BIT B1, B2;

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
  F[1] = 0;
  for (int i = 2; i <= N; ++i)
    F[i] = add(F[i - 1], (i - 1) / 2.0);
}

void solve() {
  double ans = 0;
  for (int i = 1; i <= N; ++i) {
    ans = add(ans, B1.qrange(A[i], N));
    B1.update(A[i], 1);
  }
  double sum = 0;
  for (int i = 1; i <= N; ++i) {
    double k = B2.qrange(A[i], N);
    sum = add(sum, mul(k, N - i + 1));
    B2.update(A[i], i);
  }
  for (int len = 1; len <= N; ++len)
    sum = sub(sum, mul(F[len], N - len + 1));
  ans = sub(ans, sep(sum, mul(N, N + 1) / 2.0));
  printf("%.12lf\n", ans);
}

int main() {
  init();
  solve();
  return 0;
}