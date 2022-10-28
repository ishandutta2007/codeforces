#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

bool visited[N];
string grid[N];
int perm[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    perm[a - 1] = i;
  }

  for (int i = 0; i < n; ++i) {
    grid[i] = string(n, '.');
  }

  bool ok = true;
  for (int i = 0; i < n; ++i) {
    ok &= (perm[i] == i);
  }

  int pre = n;
  int ans = (ok ? n : 0);
  if (!ok) {
    for (int i = n - 1; i >= 0; --i) {
      if (visited[i]) {
        continue;
      }

      int u = perm[i];
      visited[i] = true;
      grid[0][i] = '\\';
      if (pre < n) {
        ++ans;
        grid[n - ans][u] = '/';
        grid[n - ans][pre] = '/';
      }
      pre = i;

      while (u != i) {
        visited[u] = true;
        int v = perm[u];
        char c = (u > v ? '/' : '\\');
        ++ans;
        grid[n - ans][u] = c;
        grid[n - ans][v] = c;
        u = v;
      }
    }
  }

  cout << ans << "\n";
  for (int i = 0; i < n; ++i) {
    cout << grid[i] << "\n";
  }
}