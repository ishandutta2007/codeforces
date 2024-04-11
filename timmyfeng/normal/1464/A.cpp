#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

bool visited[N];
int nxt[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    fill(nxt, nxt + n, -1);
    fill(visited, visited + n, true);
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      nxt[--x] = --y;
      visited[x] = false;
    }

    int ans = m;
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        int u = i;
        do {
          visited[u] = true;
          u = nxt[u];
        } while (!visited[u]);
        if (u == i) {
          if (nxt[i] == i) {
            --ans;
          } else {
            ++ans;
          }
        }
      }
    }

    cout << ans << "\n";
  }
}