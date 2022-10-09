// 1217D
// colorazione di un grafo senza cicli con colori tutti uguali
// idee: coloro i "back edges" con il colore 2 e gli altri con il colore 1

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, n, m, res, check1, a, b, visited[5010];
vector<long long> adj[5010];
map<pair<long long, long long>, long long> edg;
vector<pair<long long, long long>> l;

void dfs(int p, int s) {
  if (visited[s] == 2) {
    return;
  } else if (visited[s] == 1) {
    edg[{p, s}] = 2;
    check1 = 2;
    return;
  }
  visited[s] = 1;
  for (auto u : adj[s]) {
    dfs(s, u);
  }
  visited[s] = 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  check1 = 1;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    l.push_back({a, b});
    edg[{a, b}] = 1;
  }

  for (i = 1; i <= n; i++) {
    dfs(-1, i);
  }

  cout << check1 << endl;
  for (auto u : l) {
    cout << edg[u] << ' ';
  }

  return 0;
}