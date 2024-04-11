#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> adj[N];
int cnt[N];
int dep;

void dfs(int u) {
  ++cnt[dep];
  ++dep;
  for (int c : adj[u]) {
    dfs(c);
  }
  --dep;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    adj[p].push_back(i);
  }

  dfs(1);

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += cnt[i] % 2;
  }
  cout << ans << "\n";
}