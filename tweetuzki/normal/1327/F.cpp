#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 500000, MaxM = 500000;
const int Mod = 998244353;

int N, K, M;
int L[MaxM + 5], R[MaxM + 5], X[MaxM + 5];

inline int add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inline int sub(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }
inline int mul(int x, int y) { return 1LL * x * y % Mod; }
inline void inc(int &x, int y = 1) { x = add(x, y); }
inline void dec(int &x, int y = 1) { x = sub(x, y); }

void init() {
  scanf("%d %d %d", &N, &K, &M);
  for (int i = 1; i <= M; ++i) scanf("%d %d %d", &L[i], &R[i], &X[i]);
}

inline int calc(int digit) {
  static bool banned[MaxN + 5];
  static int maxl[MaxN + 5];
  static int dif[MaxN + 5];
  static int f[MaxN + 5];
  memset(banned, false, sizeof banned);
  memset(maxl, 0, sizeof maxl);
  memset(dif, 0, sizeof dif);
  memset(f, 0, sizeof f);
  for (int i = 1; i <= M; ++i) {
    if (X[i] & (1 << digit)) {
      dif[L[i]]++;
      dif[R[i] + 1]--;
    } else maxl[R[i]] = std::max(maxl[R[i]], L[i]);
  }
  maxl[0] = -1;
  for (int i = 1; i <= N; ++i)
    maxl[i] = std::max(maxl[i], maxl[i - 1]);
  for (int i = 1, s = 0; i <= N; ++i) {
    s += dif[i];
    if (s > 0) banned[i] = true;
  }
  f[0] = 1;
  for (int i = 1, j = 0, s = 1; i <= N + 1; ++i) {
    while (j < maxl[i - 1]) {
      dec(s, f[j]);
      j++;
    }
    if (banned[i] == true) continue;
    f[i] = s;
    inc(s, f[i]);
  }
  return f[N + 1];
}

void solve() {
  int ans = 1;
  for (int i = 0; i < K; ++i)
    ans = mul(ans, calc(i));
  printf("%d\n", ans);
}

int main() {
  init();
  solve();
  return 0;
}