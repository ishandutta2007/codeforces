// modifica alfabeto per rendere le stringhe in ordine lessicografico

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, p, t, n, res, m, visited[10010], check1;
string s[110];
vector<long long> adj[10010];
vector<long long> tpl;

void dfs(int s) {
  // cout << s << ' ' << visited[s] << endl;
  if (visited[s] == 1) {
    check1 = 1;
  }
  if (visited[s] != 0) {
    return;
  }
  visited[s] = 1;
  for (auto u : adj[s]) {
    dfs(u);
  }
  tpl.push_back(s);
  visited[s] = 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (i = 0; i < 200; i++) {
    visited[i] = 0;
  }
  check1 = 0;

  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      k = 0;
      m = min(s[i].size(), s[j].size());
      while (k < m) {
        if (s[i][k] == s[j][k]) {
          k++;
        } else {
          adj[(int)s[i][k]].push_back((int)s[j][k]);
          break;
        }
      }
      if (k == m && s[i].size() > s[j].size()) {
        cout << "Impossible";
        return 0;
      }
    }
  }

  for (i = 97; i < 123; i++) {
    dfs(i);
  }

  reverse(tpl.begin(), tpl.end());
  if (check1 == 1) {
    cout << "Impossible";
    return 0;
  }
  for (i = 0; i < tpl.size(); i++) {
    cout << (char)tpl[i];
  }

  return 0;
}