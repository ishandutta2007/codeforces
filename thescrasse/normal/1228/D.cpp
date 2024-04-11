#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, a, b, bel[100010], check1, ne[13];
vector<vector<long long>> adj;
vector<pair<long long, long long>> prs;
vector<vector<long long>> adj1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> m;
  for (i = 0; i < n; i++) {
    adj.push_back({});
    adj1.push_back({});
    bel[i] = 1;
  }
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    prs.push_back({a - 1, b - 1});
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }
  if (adj[0].empty() == false) {
    for (auto u : adj[0]) {
      bel[u] = 2;
    }
  } else {
      check1 = 4;
  }
  for (i = 0; i < n; i++) {
    if (bel[i] == 2) {
      break;
    }
  }
  if (adj[i].empty() == false) {
    for (auto u : adj[i]) {
      if (bel[u] == 2) {
        bel[u] = 3;
      }
    }
  } else {
      check1 = 4;
  }

  check1 -= 3;
  for (i = 0; i < m; i++) {
    a = prs[i].first;
    b = prs[i].second;
    if (bel[a] == bel[b]) {
      check1 = 1;
    }
  }
  for (i = 0; i < 3; i++) {
    ne[i] = 0;
  }
  for (i = 0; i < n; i++) {
    ne[bel[i] - 1]++;
  }
  for (i = 0; i < 3; i++) {
    if (ne[i] != 0) {
        check1++;
    }
    if (ne[0] * ne[1] + ne[1] * ne[2] + ne[2] * ne[0] != m) {
        check1 = 1;
    }
  }
  if (check1 != 0) {
    cout << -1 << endl;
  } else {
    for (i = 0; i < n; i++) {
      cout << bel[i] << ' ';
    }
  }

  return 0;
}