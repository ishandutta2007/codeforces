#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5, INF = 1000000007;
struct Edge { int from, to, cost; };
vector<Edge> G[maxn];
int n, m, T, _dp[maxn][maxn], fa[maxn][maxn];

int dp(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m >> T;
  for (int i = 0; i < m; ++i) {
    int a, b, w; cin >> a >> b >> w;
    G[b].push_back((Edge){ b, a, w });
  }
  memset(_dp, -1, sizeof(_dp));
  for (int i = n; i >= 0; --i) {
    if (dp(n, i) <= T) {
      stack<int> ans;
      int x = n;
      cout << i << '\n';
      int j = i;
      while (x != 1) {
        ans.push(x);
        x = fa[x][j--];
      }
      ans.push(1);
      while (ans.size()) cout << ans.top() << ' ', ans.pop();
      return 0;
    }
  }
  return 0;
}

int dp(int i, int j) {
  if (i == 1 && j == 1) return 0;
  if (j < 0) return INF;
  if (_dp[i][j] != -1) return _dp[i][j];
  _dp[i][j] = INF;
  for (Edge e : G[i]) {
    int res = dp(e.to, j - 1) + e.cost;
    if (res < _dp[i][j]) _dp[i][j] = res, fa[i][j] = e.to;
  }
  return _dp[i][j];
}