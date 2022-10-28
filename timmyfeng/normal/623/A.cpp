#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 1;

bool adj[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      adj[i][j] = (i != j);
    }
  }

  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = adj[v][u] = false;
  }

  string ans(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    if (ans[i] == 0) {
      if (count(adj[i] + 1, adj[i] + n + 1, true) == 0) {
        ans[i] = 'b';
      } else {
        queue<int> que;
        ans[i] = 'a';
        que.push(i);

        while (!que.empty()) {
          int u = que.front();
          que.pop();

          for (int c = 1; c <= n; ++c) {
            if (adj[u][c]) {
              char color = 'a' + 'c' - ans[u];
              if (ans[c] == 0) {
                ans[c] = color;
                que.push(c);
              } else if (ans[c] != color) {
                cout << "No\n";
                exit(0);
              }
            }
          }
        }
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (ans[i] == 'a' && ans[j] == 'c' && !adj[i][j]) {
        cout << "No\n";
        exit(0);
      }
    }
  }

  cout << "Yes\n";
  cout << ans.substr(1) << "\n";
}