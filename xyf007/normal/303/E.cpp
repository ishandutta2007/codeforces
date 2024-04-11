#include <bits/stdc++.h>
using namespace std;
typedef double db;
int N, l[82], r[82], V[200];
db Ans[82], F[82][82];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i)
    scanf("%d%d", l + i, r + i), V[++*V] = l[i], V[++*V] = r[i];
  sort(V + 1, V + *V + 1);
  *V = unique(V + 1, V + *V + 1) - V;
  for (int i = 1; i <= N; ++i) {
    memset(Ans, 0, sizeof Ans);
    for (int j = 1, p, m, L, R; j < *V - 1; ++j)
      if (l[i] <= V[j] && r[i] > V[j]) {
        L = V[j];
        R = V[j + 1];
        memset(F, p = m = 0, sizeof F);
        **F = 1;
        for (int k = 1; k <= N; ++k)
          if (k ^ i)
            if (r[k] <= L)
              ++p;
            else if (l[k] < R) {
              db inp = 1. * (L - l[k]) / (r[k] - l[k]),
                 inm = 1. * (R - L) / (r[k] - l[k]);
              for (int x = m; ~x; --x)
                for (int y = m - x; ~y; --y) {
                  F[x + 1][y] += F[x][y] * inp;
                  F[x][y + 1] += F[x][y] * inm;
                  F[x][y] *= 1 - inp - inm;
                }
              ++m;
            }
        db tmp = 1. * (R - L) / (r[i] - l[i]);
        for (int x = m; ~x; --x)
          for (int y = m - x; ~y; --y)
            if (F[x][y] > 1e-12)
              for (int k = x + 1 + p; k <= x + y + 1 + p; ++k)
                Ans[k] += F[x][y] / (y + 1) * tmp;
      }
    for (int i = 1; i <= N; ++i) printf("%.8lf ", Ans[i]);
    puts("");
  }
}