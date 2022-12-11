#include <cstdio>
#include <cstring>

const int MaxN = 1000 + 5, MaxD = 50 + 5;
const int MaxV = 50000 + 5;
const int Mod = 1000000007;

int N, D, V;
char S[MaxN];
char X[MaxD], Y[MaxD];
int Ch[MaxV][10], Fail[MaxV];
int F[MaxD][MaxV][2];
bool Tag[MaxV];

inline int add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inline int sub(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }
inline int mul(int x, int y) { return 1LL * x * y % Mod; }
inline void inc(int &x, int y = 1) { x = add(x, y); }

void init() {
  scanf("%s", S + 1);
  N = strlen(S + 1);
  scanf("%s", X + 1);
  scanf("%s", Y + 1);
  D = strlen(X + 1);
  X[D]--;
  for (int i = D; i >= 1; --i) {
    if (X[i] >= '0') break;
    X[i] += 10;
    X[i - 1]--;
  }
}

inline void insert(char *s) {
  int u = 0;
  for (int i = 1; s[i]; ++i) {
    int c = s[i] - '0';
    if (Ch[u][c] == 0) Ch[u][c] = ++V;
    u = Ch[u][c];
  }
  Tag[u] = true;
}

void getFail() {
  static int que[MaxV];
  int head = 1, tail = 0;
  for (int c = 0; c < 10; ++c)
    if (Ch[0][c] != 0) que[++tail] = Ch[0][c];
  while (head <= tail) {
    int u = que[head++];
    for (int c = 0; c < 10; ++c) {
      if (Ch[u][c] == 0) Ch[u][c] = Ch[Fail[u]][c];
      else {
        Fail[Ch[u][c]] = Ch[Fail[u]][c];
        Tag[Ch[u][c]] |= Tag[Fail[Ch[u][c]]];
        que[++tail] = Ch[u][c];
      }
    }
  }
}

inline int calc(char *s) {
  memset(F, 0, sizeof F);
  F[0][0][1] = 1;
  for (int i = 1; i <= D; ++i) {
    for (int u = 0; u <= V; ++u) {
      if (Tag[u] == true) continue;
      for (int limit = 0; limit <= 1; ++limit) {
        int mx = 9;
        if (limit == 1) mx = s[i] - '0';
        for (int c = 0; c <= mx; ++c) {
          int v = Ch[u][c], newLimit = (c == mx && limit == 1);
          inc(F[i][v][newLimit], F[i - 1][u][limit]);
        }
      }
    }
  }
  int ans = 0;
  for (int u = 0; u <= V; ++u) {
    if (Tag[u] == true) continue;
    for (int limit = 0; limit <= 1; ++limit)
      inc(ans, F[D][u][limit]);
  }
  return ans;
}

inline int getMod(char *s) {
  int r = 0;
  for (int i = 1; i <= D; ++i)
    r = add(mul(r, 10), s[i] - '0');
  return r;
}

void solve() {
  for (int st = 1; st + D / 2 - 1 <= N; ++st) {
    static char s[MaxD];
    for (int i = st; i < st + D / 2; ++i) s[i - st + 1] = S[i];
    s[D / 2 + 1] = '\0';
    insert(s);
  }
  getFail();
  int ans = sub(calc(Y), calc(X));
  ans = sub(sub(getMod(Y), getMod(X)), ans);
  printf("%d\n", ans);
}

int main() {
  init();
  solve();
  return 0;
}