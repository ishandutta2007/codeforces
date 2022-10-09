// 1257E
// scambio problemi per avere subarray consecutivi
// idee: dp (considero i primi k problemi e fisso la posizione dell'ultimo)

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, k2, k3, t, n, res, a, b, check1, s, w[200010], dp[200010][5];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> k1 >> k2 >> k3;
  n = k1 + k2 + k3;
  for (i = 0; i < k1; i++) {
    cin >> a;
    w[a] = 1;
  }
  for (i = 0; i < k2; i++) {
    cin >> a;
    w[a] = 2;
  }
  for (i = 0; i < k3; i++) {
    cin >> a;
    w[a] = 3;
  }

  for (i = 1; i <= 3; i++) {
    dp[0][i] = 0;
  }

  for (i = 1; i <= n; i++) {
    dp[i][1] = dp[i - 1][1];
    if (w[i] != 1) {
      dp[i][1]++;
    }
    dp[i][2] = min({dp[i - 1][1], dp[i - 1][2]});
    if (w[i] != 2) {
      dp[i][2]++;
    }
    dp[i][3] = min({dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]});
    if (w[i] != 3) {
      dp[i][3]++;
    }
  }

  cout << min({dp[n][1], dp[n][2], dp[n][3]});

  return 0;
}