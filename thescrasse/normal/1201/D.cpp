// 1257E
// prendere tutti i tesori senza scendere e salendo solo nelle colonne verdi
// idee: dp (considero la distanza da percorrere per arrivare ai tesori alle estremit in ogni riga)

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, n, res, a, b, check1, s, m, q, t[200010][5], dp[200010][5], p, c[200010][5];
vector<long long> g;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  res = 1;
  cin >> n >> m >> k1 >> q;
  for (i = 1; i <= n; i++) {
    t[i][1] = 2000010;
    t[i][2] = -1;
  }
  for (i = 0; i < k1; i++) {
    cin >> a >> b;
    t[a][1] = min(t[a][1], b);
    t[a][2] = max(t[a][2], b);
  }

  for (i = 0; i < q; i++) {
    cin >> a;
    g.push_back(a);
  }
  sort(g.begin(), g.end());
  for (i = 0; i < q - 1; i++) {
    for (j = g[i] + 1; j < g[i + 1]; j++) {
      c[j][1] = g[i];
      c[j][2] = g[i + 1];
    }
  }
  for (j = 1; j < g[0]; j++) {
    c[j][2] = g[0];
    c[j][1] = 2000010;
  }
  for (j = g[q - 1] + 1; j <= m; j++) {
    c[j][2] = 2000010;
    c[j][1] = g[q - 1];
  }

  for (i = 0; i < q; i++) {
    c[g[i]][1] = g[i];
    c[g[i]][2] = g[i];
  }

  k = 0;
  for (i = 1; i <= n; i++) {
    if (k == 0 && t[i][2] != -1) {
      res = i;
      if (i == 1) {
        dp[i][1] = (t[i][2] - 1) + (t[i][2] - t[i][1]);
        dp[i][2] = t[i][2] - 1;
      } else {
        dp[i][1] = (c[1][2] - 1) + abs(t[i][2] - c[1][2]) + (t[i][2] - t[i][1]);
        dp[i][2] = (c[1][2] - 1) + abs(t[i][1] - c[1][2]) + (t[i][2] - t[i][1]);
      }
      k = i;
    } else if (t[i][2] != -1) {
      res = i;
      dp[i][1] = t[i][2] - t[i][1] + min(
      dp[k][1] + min(abs(t[k][1] - c[t[k][1]][1]) + abs(t[i][2] - c[t[k][1]][1]),
      abs(t[k][1] - c[t[k][1]][2]) + abs(t[i][2] - c[t[k][1]][2])),
      dp[k][2] + min(abs(t[k][2] - c[t[k][2]][1]) + abs(t[i][2] - c[t[k][2]][1]),
      abs(t[k][2] - c[t[k][2]][2]) + abs(t[i][2] - c[t[k][2]][2])));
      dp[i][2] = t[i][2] - t[i][1] + min(
      dp[k][1] + min(abs(t[k][1] - c[t[k][1]][1]) + abs(t[i][1] - c[t[k][1]][1]),
      abs(t[k][1] - c[t[k][1]][2]) + abs(t[i][1] - c[t[k][1]][2])),
      dp[k][2] + min(abs(t[k][2] - c[t[k][2]][1]) + abs(t[i][1] - c[t[k][2]][1]),
      abs(t[k][2] - c[t[k][2]][2]) + abs(t[i][1] - c[t[k][2]][2])));
      k = i;
    } else {
      dp[i][1] = dp[k][1];
      dp[i][2] = dp[k][2];
    }
  }

  res = res + min(dp[n][1], dp[n][2]) - 1;

  cout << res;

  return 0;
}