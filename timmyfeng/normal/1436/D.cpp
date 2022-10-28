#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

vector<int> adj[N];
long long a[N];
int leaves[N];

long long ans;

void dfs(int u) {
  leaves[u] = adj[u].empty();
  for (auto c : adj[u]) {
    dfs(c);
    a[u] += a[c];
    leaves[u] += leaves[c];
  }

  if (a[u] > 0) {
    ans = max(ans, (a[u] - 1) / leaves[u] + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    adj[p - 1].push_back(i);
  }

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  dfs(0);

  cout << ans << "\n";
}