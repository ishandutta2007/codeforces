#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

vector<int> post[N];
vector<int> pre[N];
vector<int> adj[N];
bool dp_present[N];
bool dp_absent[N];
int option[N];

void dfs(int u, int p) {
  for (int c : adj[u]) {
    if (c != p) {
      dfs(c, u);
      if (dp_present[c] && dp_absent[c]) {
        option[u] = c;
      }
      if (dp_absent[c]) {
        post[u].push_back(c);
      } else {
        pre[u].push_back(c);
      }
    }
  }

  dp_absent[u] = (option[u] != 0 || int(post[u].size()) % 2 == 0);
  dp_present[u] = (option[u] != 0 || int(post[u].size()) % 2 == 1);

  if (!dp_present[u] && !dp_absent[u]) {
    cout << "NO\n";
    exit(0);
  }
}

void dfs_print(int u, bool p) {
  int cnt = int(pre[u].size() + post[u].size()) + p;

  for (int c : pre[u]) {
    dfs_print(c, true);
    --cnt;
  }

  if (cnt % 2 == 1) {
    assert(option[u] != 0);
    dfs_print(option[u], true);
    post[u].erase(find(post[u].begin(), post[u].end(), option[u]));
  }

  cout << u << "\n";

  for (int c : post[u]) {
    dfs_print(c, false);
    --cnt;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int p;
    cin >> p;
    if (p != 0) {
      adj[p].push_back(i);
      adj[i].push_back(p);
    }
  }

  dfs(1, 0);
  if (!dp_absent[1]) {
    cout << "NO\n";
    exit(0);
  }

  cout << "YES\n";
  dfs_print(1, false);
}