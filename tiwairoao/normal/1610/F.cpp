#include <bits/stdc++.h>

const int N = 300000;

int to[2][4*N + 5], ecnt[2];
std::vector<int>G[2][N + 5];
int adde(int u, int v, int w) {
  int p = (ecnt[w]++); to[w][p] = v, G[w][u].push_back(p);
  p = (ecnt[w]++), to[w][p] = u, G[w][v].push_back(p);
  return p >> 1;
}

int tag[2][4*N + 5], cur[2][N + 5], ans[2][2*N + 5], cnt[2];
void dfs(int x, int w) {
  for (int &i = cur[w][x]; i < (int)G[w][x].size(); ) {
    if (tag[w][G[w][x][i]]) {i++; continue;}
    int e = G[w][x][i++]; tag[w][e] = 1, tag[w][e ^ 1] = -1;
    dfs(to[w][e], w), ans[w][cnt[w]++] = e;
  }
}

int d[2][N + 5], lnk[2][N + 5], clr[N + 5];
void run(int x, int c) {
  if (clr[x]) {assert (clr[x] == c); return;}
  clr[x] = c, run(lnk[0][x], -c);
  if (d[0][lnk[1][x]] & 1) run(lnk[1][x], -c);
}

int u[N + 5], v[N + 5], w[N + 5], n, m;

int id[N + 5];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &u[i], &v[i], &w[i]), w[i]--;
    id[i] = adde(u[i], v[i], w[i]), d[w[i]][u[i]]++, d[w[i]][v[i]]++;
  }

  int sum = 0;
  for (int i = 1; i <= n; i++) if (d[0][i] & 1) adde(0, i, 0), sum++;
  for (int i = 1; i <= n; i++) if (d[1][i] & 1) adde(0, i, 1);

  for (int o = 0; o < 2; o++) {
    for (int i = 0; i <= n; i++) dfs(i, o);
    std::reverse(ans[o], ans[o] + cnt[o]);
    for (int i = 0; i < cnt[o]; i++) {
      if (!to[o][ans[o][i] ^ 1]) {
        int j; for (j = i; to[o][ans[o][j]]; j++) continue;
        lnk[o][to[o][ans[o][i]]] = to[o][ans[o][j] ^ 1];
        lnk[o][to[o][ans[o][j] ^ 1]] = to[o][ans[o][i]];
        i = j;
      }
    }
  }

  for (int i = 1; i <= n; i++) if (d[0][i] & d[1][i] & 1)
    if (!clr[i]) run(i, 1);

  for (int i = 0; i < cnt[0]; i++) {
    if (!to[0][ans[0][i] ^ 1]) {
      int j; for (j = i; to[0][ans[0][j]]; j++) continue;

      if (clr[to[0][ans[0][i]]] == -1 || clr[to[0][ans[0][j] ^ 1]] == 1) {
        for (int k = i + 1; k <= j - 1; k++)
          std::swap(tag[0][ans[0][k]], tag[0][ans[0][k] ^ 1]);
      }

      i = j;
    }
  }
  
  for (int i = 0; i < cnt[1]; i++) {
    if (!to[1][ans[1][i] ^ 1]) {
      int j; for (j = i; to[1][ans[1][j]]; j++) continue;

      if (clr[to[1][ans[1][i]]] == 1 || clr[to[1][ans[1][j] ^ 1]] == -1) {
        for (int k = i + 1; k <= j - 1; k++)
          std::swap(tag[1][ans[1][k]], tag[1][ans[1][k] ^ 1]);
      }

      i = j;
    }
  }

  printf("%d\n", sum);
  for (int i = 1; i <= m; i++) putchar(tag[w[i]][id[i] << 1] == 1 ? '1' : '2');
  puts("");
}