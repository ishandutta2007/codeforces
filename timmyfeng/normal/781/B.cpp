#include <bits/stdc++.h>
using namespace std;

struct twosat {

  vector<vector<int>> adj;
  vector<vector<int>> jda;
  vector<int> component;
  vector<bool> visited;
  vector<int> order;
  vector<bool> ans;
  int n;

  twosat(int n) : n(n) {
    component.resize(2 * n);
    visited.resize(2 * n);
    adj.resize(2 * n);
    jda.resize(2 * n);
    ans.resize(2 * n);
  }

  void add_edge(int u, bool s, int v, bool t) {
    adj[2 * u + !s].push_back(2 * v + t);
    adj[2 * v + !t].push_back(2 * u + s);
    jda[2 * v + t].push_back(2 * u + !s);
    jda[2 * u + s].push_back(2 * v + !t);
  }

  void dfs_sort(int u) {
    visited[u] = true;
    for (auto c : adj[u]) {
      if (!visited[c]) {
        dfs_sort(c);
      }
    }
    order.push_back(u);
  }

  void dfs_color(int u, int id) {
    component[u] = id;
    for (auto c : jda[u]) {
      if (component[c] == 0) {
        dfs_color(c, id);
      }
    }
  }

  bool solve() {
    for (int i = 0; i < 2 * n; ++i) {
      if (!visited[i]) {
        dfs_sort(i);
      }
    }

    int cnt = 0;
    while (!order.empty()) {
      int u = order.back();
      order.pop_back();
      if (!component[u]) {
        dfs_color(u, ++cnt);
      }
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (component[i * 2] == component[i * 2 + 1]) {
        ok = false;
      } else if (component[i * 2] > component[i * 2 + 1]) {
        ans[i] = true;
      }
    }
    return ok;
  }

};

const int N = 1000;

string options[N][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;
    options[i][0] = a.substr(0, 3);
    options[i][1] = a.substr(0, 2) + b[0];
  }

  twosat flower(n);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        for (auto ii : {true, false}) {
          for (auto jj : {true, false}) {
            if (options[i][ii] == options[j][jj]) {
              flower.add_edge(i, !ii, j, !jj);
              if (!ii && !jj) {
                flower.add_edge(i, false, j, true);
              }
            }
          }
        }
      }
    }
  }

  if (!flower.solve()) {
    cout << "NO\n";
    exit(0);
  }

  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    cout << options[i][!flower.ans[i]] << "\n";
  }
}