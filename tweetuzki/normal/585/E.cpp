#include <cstdio>

const int MaxN = 500000, MaxA = 10000000;
const int Mod = 1000000007;

int N;
int Buc[MaxA + 5];
bool NotPrime[MaxA + 5];
int Prs[MaxA / 10 + 5], Prc;
int Mu[MaxA + 5], Pw2[MaxA + 5];
int Fu[MaxA + 5];
int F[MaxA + 5], G[MaxA + 5];

inline int add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inline int sub(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }
inline int mul(int x, int y) { return 1LL * x * y % Mod; }
inline void inc(int &x, int y = 1) { x = add(x, y); }
inline void dec(int &x, int y = 1) { x = sub(x, y); }

void linearSieve(const int n) {
  Mu[1] = 1;
  NotPrime[1] = true;
  for (int i = 2; i <= n; ++i) {
    if (NotPrime[i] == false) {
      Prs[++Prc] = i;
      Mu[i] = -1;
    }
    for (int j = 1; j <= Prc; ++j) {
      int k = i * Prs[j];
      if (k > n) break;
      NotPrime[k] = true;
      if (i % Prs[j] == 0) break;
      Mu[k] = -Mu[i];
    }
  }
}

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    int x;
    scanf("%d", &x);
    Buc[x]++;
  }
  linearSieve(MaxA);
  Pw2[0] = 1;
  for (int i = 1; i <= MaxA; ++i) Pw2[i] = mul(Pw2[i - 1], 2);
}

void solve() {
  for (int i = 1; i <= MaxA; ++i)
    for (int j = i; j <= MaxA; j += i)
      Fu[i] += Buc[j];
  for (int i = 1; i <= MaxA; ++i)
    for (int j = 1; i * j <= MaxA; ++j) {
      int f = Pw2[Fu[i * j]] - 1;
      if (Mu[j] == 1) inc(F[i], f);
      if (Mu[j] == -1) dec(F[i], f);
      if (Mu[i] == 1) inc(G[i * j], Fu[i]);
      if (Mu[i] == -1) dec(G[i * j], Fu[i]);
    }
  int ans = 0;
  for (int i = 2; i <= MaxA; ++i)
    inc(ans, mul(F[i], G[i]));
  printf("%d\n", ans);
}

int main() {
  init();
  solve();
  return 0;
}