#include <bits/stdc++.h>
using namespace std;

int i, i1, j, k, t, n, m, res, a, b, c, dp[5010][5010], pathr[5010][5010], visitedcount;
bool visited[5010];
vector<pair<int, int>> adj[5010], reversedadj[5010];
vector<int> topological, resv;

void dfs(int s) {
  //cout << s << endl;
  if (visited[s]) {
    return;
  }
  visitedcount++;
  visited[s] = true;
  for (auto u : adj[s]) {
    dfs(u.first);
  }
  topological.push_back(s);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> m >> t;
  for (i = 0; i < m; i++) {
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    reversedadj[b].push_back({a, c});
  }

  k = 1;
  visitedcount = 0;
  while (k <= n && visitedcount != n) {
    if (visited[k]) {
      k++;
      continue;
    }
    dfs(k);
    k++;
  }

  reverse(topological.begin(), topological.end());

  for (i = 1; i <= n; i++) {
    dp[i][0] = 0;
    pathr[i][0] = 0;
    for (j = 1; j <= n; j++) {
      dp[i][j] = 1000000010;
      pathr[i][j] = 0;
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 1; j <= n; j++) {
      for (auto u : reversedadj[topological[i]]) {
        if (u.first == 1 || j != 1) {
          if ((long long)dp[u.first][j - 1] + u.second < (long long)dp[topological[i]][j]) {
            pathr[topological[i]][j] = u.first;
          }
          dp[topological[i]][j] = min({(long long)dp[topological[i]][j], (long long)dp[u.first][j - 1] + u.second, (long long)1000000010});
        }
      }
    }
  }

  res = 0;
  for (j = 1; j <= n; j++) {
    if (dp[n][j] <= t) {
      res = j;
    }
  }

  j = n;
  k = res;
  while (j != 0) {
    resv.push_back(j);
    j = pathr[j][k];
    k--;
  }

  reverse(resv.begin(), resv.end());

  cout << res + 1 << endl;
  for (auto u : resv) {
    cout << u << ' ';
  }
  /*cout << endl;

  for (i = 0; i < n; i++) {
    cout << topological[i] << ' ';
  }
  cout << endl;

  for (i = 0; i < n; i++) {
    for (j = 1; j <= n; j++) {
      cout << dp[topological[i]][j] << ' ';
    }
    cout << endl;
  }

  cout << endl;

  for (i = 0; i < n; i++) {
    for (j = 1; j <= n; j++) {
      cout << pathr[topological[i]][j] << ' ';
    }
    cout << endl;
  }*/

  return 0;
}