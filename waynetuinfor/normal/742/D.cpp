#include <iostream>
#include <vector>
#include <bitset>
#define int long long
using namespace std;


const int MAXN = 1000 + 5;
vector<int> G[MAXN];
int N, M, W, w[MAXN], b[MAXN], x, y, cc, dp[MAXN];
bitset<MAXN> v;
void DFS(int);

struct Component {
  int w, b;
  vector<int> node;
} CC[MAXN];

signed main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N >> M >> W;
  for (int i = 1; i <= N; ++i) cin >> w[i];
  for (int i = 1; i <= N; ++i) cin >> b[i];
  while (M--) {
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  v.reset();
  for (int i = 1; i <= N; ++i) {
    if (!v[i]) cc++, DFS(i);
  }
  for (int i = 1; i <= cc; ++i) {
    for (int j = W; j >= 0; --j) {
      for (int k : CC[i].node) {
        if (j - w[k] >= 0) dp[j] = max(dp[j], dp[j - w[k]] + b[k]);
      }
      if (j - CC[i].w >= 0) dp[j] = max(dp[j], dp[j - CC[i].w] + CC[i].b);
    }
  }
  cout << dp[W] << '\n';
  return 0;
}

void DFS(int x) {
  v[x] = true;
  CC[cc].w += w[x];
  CC[cc].b += b[x];
  CC[cc].node.push_back(x);
  for (int u : G[x]) {
    if (!v[u]) DFS(u);
  }
}