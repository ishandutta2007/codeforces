#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, a, b, check1;
bool visited[100010], c[100010], ch[100010];
vector<long long> adj[100010], p, r;

void dfs(int s) {
  p.push_back(s);
  visited[s] = true;
  for (auto u : adj[s]) {
    if (visited[u] == false) {
      dfs(u);
      ch[s] = true;
      break;
    }
  }
  if (ch[s] == false) {
    for (auto u : adj[s]) {
      c[u] = true;
    }
    for (i = 0; i < p.size(); i++) {
      if (c[p[i]] == true) {
        ch[s] = true;
      }
      if (ch[s] == true) {
        r.push_back(p[i]);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> m >> k;
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1);

  cout << r.size() << endl;
  for (i = 0; i < r.size(); i++) {
    cout << r[i] << ' ';
  }

  return 0;
}