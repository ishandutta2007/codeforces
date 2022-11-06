#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5;
int n, t[maxn], fa[maxn], root, sum[maxn], cnt, tot;
vector<int> G[maxn], ans;
bool cut[maxn];

void dfs(int);
int dp(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> fa[i] >> t[i];
    if (!fa[i]) { root = i; continue; }
    G[fa[i]].push_back(i);
    G[i].push_back(fa[i]);
  }
  dfs(root);
  tot = sum[root];
  if (tot % 3 != 0) return cout << "-1\n", 0;
  dp(root);
  if (cnt != 2) return cout << "-1\n", 0;
  if (ans[0] == root || ans[1] == root) return cout << "-1\n", 0;
  cout << ans[0] << ' ' << ans[1] << '\n';
}

void dfs(int x) {
  sum[x] = t[x];
  for (int u : G[x]) if (u != fa[x]) {
    dfs(u);
    sum[x] += sum[u];
  }
}

int dp(int x) {
  int cut = 0;
  for (int u : G[x]) if (u != fa[x]) cut += dp(u);
  if (sum[x] - cut == tot / 3 && cnt < 2) {
    ++cnt;
    ans.push_back(x);
    cut = sum[x];
  }
  return cut;
}