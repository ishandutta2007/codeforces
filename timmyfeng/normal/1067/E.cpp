#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;
const int MOD = (119 << 23) + 1;

int add(int a, int b) {
  return (a += b) < MOD ? a : a - MOD;
}

int sub(int a, int b) {
  return (a -= b) < 0 ? a + MOD : a;
}

int mul(int a, int b) {
  return 1LL * a * b % MOD;
}

vector<int> adj[N];
int ans;

int dfs(int u, int p) {
  int prob = 1;
  for (int c : adj[u]) {
    if (c != p) {
      prob = mul(prob, sub(1, dfs(c, u)));
    }
  }
  ans = add(ans, sub(1, prob));
  return mul(prob, (MOD + 1) / 2);
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

  dfs(1, 0);
  for (int i = 0; i < n; ++i) {
    ans = add(ans, ans);
  }
  cout << ans << "\n";
}