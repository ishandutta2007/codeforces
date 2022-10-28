#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 23;

bool visited[N];
bool cnt[N];
int n;

void dfs(int u) {
  if (visited[u])
    return;
  visited[u] = true;
  if (u < (1 << n)) {
    for (int i = 0; i < n; ++i) {
      if ((u & (1 << i)) == 0) {
        dfs(u ^ (1 << i));
      }
    }
    int complement = ((1 << n) - 1) ^ u;
    if (cnt[complement]) {
      dfs((1 << n) + complement);
    }
  } else {
    dfs(u - (1 << n));
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    cnt[a] = true;
  }

  int ans = 0;
  for (int i = 0; i < (1 << n); ++i) {
    if (cnt[i] && !visited[(1 << n) + i]) {
      dfs((1 << n) + i);
      ++ans;
    }
  }
  cout << ans << "\n";
}