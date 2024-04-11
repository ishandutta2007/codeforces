#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int MaxN = 400000, MaxV = 1000, Alpha = 14;
const long long NeINF = 0x8080808080808080;

int N, V;
char S[MaxN + 5];
int Ch[MaxV + 5][Alpha], Fail[MaxV + 5], Weight[MaxV + 5];
long long F[MaxV + 5][1 << Alpha];
int PopCount[1 << Alpha];
std::vector<int> Tr[MaxV + 5];

void insert(char *s, int v) {
  int u = 0;
  for (int i = 1; s[i]; ++i) {
    int c = s[i] - 'a';
    if (Ch[u][c] == 0) Ch[u][c] = ++V;
    u = Ch[u][c];
  }
  Weight[u] += v;
}

void getFail() {
  static int que[MaxV + 5];
  int head = 1, tail = 0;
  for (int c = 0; c < Alpha; ++c)
    if (Ch[0][c] != 0) que[++tail] = Ch[0][c];
  while (head <= tail) {
    int u = que[head++];
    Tr[Fail[u]].push_back(u);
    for (int c = 0; c < Alpha; ++c) {
      int &v = Ch[u][c];
      if (v == 0) v = Ch[Fail[u]][c];
      else {
        Fail[v] = Ch[Fail[u]][c];
        que[++tail] = v;
      }
    }
  }
}

void dfs(int u) {
  for (int v : Tr[u]) {
    Weight[v] += Weight[u];
    dfs(v);
  }
}

void init() {
  int k;
  scanf("%d", &k);
  for (int i = 1; i <= k; ++i) {
    static char t[MaxV + 5];
    int c;
    scanf("%s %d", t + 1, &c);
    insert(t, c);
  }
  scanf("%s", S + 1);
  N = (int) strlen(S + 1);
  for (int i = 1; i < (1 << Alpha); ++i)
    PopCount[i] = PopCount[i >> 1] + (i & 1);
}

void solve() {
  getFail();
  dfs(0);
  memset(F, 0x80, sizeof F);
  F[0][0] = 0;
  long long ans = NeINF;
  for (int i = 1, j = 0, num = 0; j <= N; j = i++, ++num) {
    while (i <= N && S[i] != '?') i++;
    for (int u = 0; u <= V; ++u) {
      int x = u; long long sum = 0;
      for (int k = j + 1; k < i; ++k) {
        x = Ch[x][S[k] - 'a'];
        sum += Weight[x];
      }
      for (int s = 0; s < (1 << Alpha); ++s) {
        if (PopCount[s] != num) continue;
        if (F[u][s] == NeINF) continue;
        if (i > N) ans = std::max(ans, F[u][s] + sum);
        else {
          for (int c = 0; c < Alpha; ++c) {
            if (s & (1 << c)) continue;
            int v = Ch[x][c];
            F[v][s | (1 << c)] = std::max(F[v][s | (1 << c)], F[u][s] + sum + Weight[v]);
          }
        }
      }
    }
  }
  printf("%lld\n", ans);
}

int main() {
  init();
  solve();
  return 0;
}