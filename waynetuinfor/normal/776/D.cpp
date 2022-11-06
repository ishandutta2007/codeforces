#include <bits/stdc++.h>
#define Lock(i) (i << 1)
#define Unlock(i) (i << 1 | 1)
using namespace std;

const int maxn = 100000 + 5;
int n, m, r[maxn], c, S[maxn << 1];
vector<int> sw[maxn];
vector<int> G[maxn << 1];
bool v[maxn << 1];

bool dfs(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> r[i];
  for (int i = 0; i < m; ++i) {
    int k, x; cin >> k;
    while (k--) cin >> x, sw[x].push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    if (!r[i]) {
      G[Lock(sw[i][0])].push_back(Unlock(sw[i][1]));
      G[Unlock(sw[i][1])].push_back(Lock(sw[i][0]));
      G[Unlock(sw[i][0])].push_back(Lock(sw[i][1]));
      G[Lock(sw[i][1])].push_back(Unlock(sw[i][0]));
    } else {
      G[Lock(sw[i][0])].push_back(Lock(sw[i][1]));
      G[Lock(sw[i][1])].push_back(Lock(sw[i][0]));
      G[Unlock(sw[i][0])].push_back(Unlock(sw[i][1]));
      G[Unlock(sw[i][1])].push_back(Unlock(sw[i][0]));
    }
  }
  for (int i = 0; i < m * 2; i += 2) {
    if (!v[i] && !v[i + 1])  {
      c = 0;
      if (!dfs(i)) {
        while (c) v[S[--c]] = false;
        if (!dfs(i + 1)) return cout << "NO\n", 0;
      }
    }
  }
  cout << "YES\n";
  return 0;
}

bool dfs(int x) {
  if (v[x ^ 1]) return false;
  if (v[x]) return true;
  v[x] = true;
  S[c++] = x;
  for (int u : G[x]) if (!dfs(u)) return false;
  return true;
}