#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, a, b, dist[200010], d, s, x, ti;
bool visited[200010];
vector<long long> sp, di, df;
vector<long long> adj[200010];
vector<vector<long long>> ot;
queue<long long> q;

void bfs(int x) {
  visited[x] = true;
  dist[x] = 0;
  q.push(x);

  while (!q.empty()) {
    s = q.front();
    q.pop();
    for (auto u : adj[s]) {
      if (visited[u]) {
        continue;
      }
      visited[u] = true;
      dist[u] = dist[s] + 1;
      q.push(u);
    }
  }

  for (i = 0; i < n; i++) {
    visited[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> m >> k;
  for (i = 0; i < k; i++) {
    cin >> a;
    sp.push_back(a);
  }
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  bfs(1);
  for (auto u : sp) {
    di.push_back(dist[u]);
  }

  ti = dist[n];

  bfs(n);
  for (auto u : sp) {
    df.push_back(dist[u]);
  }

  for (i = 0; i < k; i++) {
    ot.push_back({di[i] - df[i], di[i], df[i]});
    //cout << sp[i] << ' ' << ot[i][0] << ' ' << ot[i][1] << ' ' << ot[i][2] << endl;
  }

  m = 0;
  sort(ot.begin(), ot.end());
  for (i = k - 1; i >= 1; i--) {
    m = max(m, ot[i][2]);
    ot[i][2] = m;
  }
  m = 0;
  for (i = 0; i < k - 1; i++) {
    m = max(m, ot[i][1] + ot[i + 1][2]);
  }

  cout << min(m + 1, ti);

  return 0;
}