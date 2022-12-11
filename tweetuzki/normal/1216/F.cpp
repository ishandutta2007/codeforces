#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 5000000 + 5;
const long long INF = 0x7F7F7F7F7F7F7F7F;

int Te, N, K;
char S[MaxN];
long long F[MaxN];
int Que[MaxN], Head, Tail;
char Fl[1 << 27], *Lk = Fl;

inline int nextInt() {
  int x = 0; char c;
  do c = *Lk++; while (c < '0' || c > '9');
  do x = (x << 1) + (x << 3) + c - '0', c = *Lk++; while (c >= '0' && c <= '9');
  return x;
}

inline void nextString(char *s) {
  char c; int lk = 1;
  do c = *Lk++; while (c < '0' || c > '9');
  do s[lk++] = c, c = *Lk++; while (c >= '0' && c <= '9');
  s[lk] = '\0';
}

void init() {
  Head = 1, Tail = 0;
  memset(F, 0x7F, sizeof F);
  N = nextInt(), K = nextInt();
  nextString(S);
}

void solve() {
  F[0] = 0;
  Que[++Tail] = 0;
  for (int i = 1; i <= N; ++i) {
    F[i] = F[i - 1] + i;
    if (i == N) {
      for (int m = std::max(N - K, 1); m <= N; ++m) {
        if (S[m] == '0') continue;
        int l = std::max(1, m - K);
        while (Head <= Tail && Que[Head] < l - 1) Head++;
        F[i] = std::min(F[i], F[Que[Head]] + m);
      }
    } else {
      if (i > K) {
        int m = i - K;
        if (S[m] == '1') {
          int l = std::max(1, m - K);
          while (Head <= Tail && Que[Head] < l - 1) Head++;
          F[i] = std::min(F[i], F[Que[Head]] + m);
        }
      }
      while (Head <= Tail && F[Que[Tail]] >= F[i]) Tail--;
      Que[++Tail] = i;
    }
  }
  printf("%lld\n", F[N]);
}

int main() {
  fread(Fl, 1, 1 << 27, stdin);
  Te = 1;
  for (int t = 1; t <= Te; ++t) {
    init();
    solve();
  }
  return 0;
}