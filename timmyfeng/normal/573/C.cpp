#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;

vector<int> adj[N];

int dfs(int u, bool sure, int p = 0) {
  vector<int> freq(4);
  for (auto c : adj[u]) {
    if (c != p) {
      int type = dfs(c, sure, u);
      if (type == 0) {
        if (sure) {
          cout << "No\n";
          exit(0);
        } else {
          dfs(c, true);
          cout << "Yes\n";
          exit(0);
        }
      }
      ++freq[type];
    }
  }

  if (freq[1] > 2) {
    cout << "No\n";
    exit(0);
  }

  if (freq[1] == 2) {
    return 0;
  } else if (freq[1] > 0 || freq[2] > 0 || freq[3] > 2) {
    return 1;
  } else if (freq[3] == 2) {
    return 2;
  } else {
    return 3;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, false);

  cout << "Yes\n";
}