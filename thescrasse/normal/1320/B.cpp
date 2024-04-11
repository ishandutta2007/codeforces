#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res1, res2, a, b, dist[200010], pt[200010], check1;
vector<long long> adj[200010], revadj[200010];
queue<long long> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    revadj[b].push_back(a);
  }

  cin >> k;
  for (i = 0; i < k; i++) {
    cin >> pt[i];
  }

  for (i = 1; i <= n; i++) {
    dist[i] = -1;
  }

  a = pt[k - 1];
  q.push(a);
  dist[a] = 0;
  while (!q.empty()) {
    a = q.front();
    q.pop();
    for (auto u : revadj[a]) {
      if (dist[u] == -1) {
        dist[u] = dist[a] + 1;
        q.push(u);
      }
    }
  }

  res1 = 0;
  res2 = 0;
  for (i = 1; i < k; i++) {
    if (dist[pt[i]] == dist[pt[i - 1]] - 1) {
      check1 = 0;
      for (auto u : adj[pt[i - 1]]) {
        if (dist[u] == dist[pt[i - 1]] - 1) {
          check1++;
        }
      }
      if (check1 >= 2) {
        res2++;
      }
    } else {
      res1++;
      res2++;
    }
  }

  cout << res1 << ' ' << res2;

  return 0;
}