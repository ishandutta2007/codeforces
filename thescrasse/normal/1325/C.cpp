#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, check1, a, b, degr[100010], okk[7];
bool visited[100010];
vector<long long> adj[100010];
vector<pair<long long, long long>> el;

void dfs(int s) {
    if (visited[s]) {
        return;
    }
    visited[s] = true;
    for (auto u : adj[s]) {
        dfs(u);
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n;
  for (i = 0; i < n - 1; i++) {
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
      el.push_back({a, b});
      degr[a]++;
      degr[b]++;
  }

  if (n == 2) {
      cout << 0;
      return 0;
  }

  k = 0;
  for (i = 1; i <= n; i++) {
      if (degr[i] == 1) {
          okk[k] = i;
          k++;
      }
      if (k == 3) {
          break;
      }
  }
  if (k == 2) {
      for (i = 0; i < n - 1; i++) {
          cout << i << endl;
      }
      return 0;
  } else {
      k = 3;
      for (auto u : el) {
          if (u.first == okk[0] || u.second == okk[0]) {
              cout << 0 << endl;
          } else if (u.first == okk[1] || u.second == okk[1]) {
              cout << 1 << endl;
          } else if (u.first == okk[2] || u.second == okk[2]) {
              cout << 2 << endl;
          } else {
              cout << k << endl;
              k++;
          }
      }
  }

  return 0;
}