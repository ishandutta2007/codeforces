// 946D
// lezioni da saltare per minimizzare le ore buche
// idee:

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, mn[510][510], dp[510][510], x;
string a[510];
vector<long long> pos1[510];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> m >> k1;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (a[i][j] == '1') {
        pos1[i].push_back(j);
      }
    }
  }

  for (i = 0; i < n; i++) {
    mn[i][0] = 0;
    for (j = 1; j <= m; j++) {
      mn[i][j] = 1010;
    }
    for (j = 1; j <= m; j++) {
      // cout << pos1[i].size() << endl;
      x = pos1[i].size();
      for (k = 0; k <= x - j; k++) {
        // cout << i << ' ' << j << ' ' << k << endl;
        mn[i][j] = min(mn[i][j], pos1[i][k + j - 1] - pos1[i][k] + 1);
      }
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j <= k1; j++) {
      dp[i][j] = 1000010;
    }
  }

  for (j = 0; j <= pos1[0].size(); j++) {
    dp[0][j] = mn[0][pos1[0].size() - j];
  }

  for (i = 1; i < n; i++) {
    for (j = 0; j <= k1; j++) {
      for (k = 0; k <= j; k++) {
        if (pos1[i].size() >= k) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + mn[i][pos1[i].size() - k]);
        }
      }
    }
  }

  if (dp[n - 1][k1] == 1000010) {
    dp[n - 1][k1] = 0;
  }

  cout << dp[n - 1][k1];

  /*for (i = 0; i < n; i++) {
    for (j = 0; j <= m; j++) {
      cout << mn[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;

  for (i = 0; i < n; i++) {
    for (j = 0; j <= k1; j++) {
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }*/

  return 0;
}