// 1272E
// mosse per passare ad un intero con parit diversa
// idee: multi-source bfs dai pari e dai dispari

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, p, res[200010], check1, a[200010], dist[200010], x;
vector<long long> adjr[200010];
queue<long long> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (i - a[i] >= 0) {
      adjr[i - a[i]].push_back(i);
    }
    if (i + a[i] < n) {
      adjr[i + a[i]].push_back(i);
    }
  }

  for (i = 0; i < n; i++) {
    dist[i] = 1000010;
  }

  for (i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      q.push(i);
      dist[i] = 0;
    }
  }
  while (!q.empty()) {
    x = q.front();
    // cout << x << endl;
    q.pop();
    for (auto u : adjr[x]) {
      if (dist[u] > dist[x] + 1) {
        dist[u] = dist[x] + 1;
        q.push(u);
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (a[i] % 2 == 1) {
      res[i] = dist[i];
    }
  }

  // cout << endl;

  for (i = 0; i < n; i++) {
    dist[i] = 1000010;
  }

  for (i = 0; i < n; i++) {
    if (a[i] % 2 == 1) {
      q.push(i);
      dist[i] = 0;
    }
  }
  while (!q.empty()) {
    x = q.front();
    // cout << x << endl;
    q.pop();
    for (auto u : adjr[x]) {
      if (dist[u] > dist[x] + 1) {
        dist[u] = dist[x] + 1;
        q.push(u);
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      res[i] = dist[i];
    }
  }

  for (i = 0; i < n; i++) {
    if (res[i] == 1000010) {
      cout << -1 << ' ';
    } else {
      cout << res[i] << ' ';
    }
  }

  return 0;
}