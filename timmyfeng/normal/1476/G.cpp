#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;
const int B = 2048;

int values[N], first[N], last[N], freq[N];
array<int, 3> queries[N];
int a[N], b[N], ans[N];

void insert(int x) {
  --last[freq[x]];
  ++values[--first[++freq[x]]];
}

void erase(int x) {
  --values[first[freq[x]--]++];
  ++last[freq[x]];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < m; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, k;
      cin >> l >> r >> k;
      queries[i] = {--l, --r, k};
    } else {
      int p, x;
      cin >> p >> x;
      queries[i] = {-1, --p, x};
    }
  }

  for (int i = 1; i <= n; ++i) {
    first[i] = n;
    last[i] = n - 1;
  }
  last[0] = n - 1;

  for (int i = 0; i <= (n - 1) / B; ++i) {
    for (int j = i; j <= (n - 1) / B; ++j) {
      copy(a, a + n, b);
      int l = 0, r = -1;

      for (int k = 0; k < m; ++k) {
        auto [x, y, z] = queries[k];
        if (x == -1) {
          if (y >= l && y <= r) {
            erase(b[y]);
            insert(z);
          }
          b[y] = z;
        } else if (x / B == i && y / B == j) {
          while (l > x) {
            insert(b[--l]);
          }
          while (r < y) {
            insert(b[++r]);
          }
          while (l < x) {
            erase(b[l++]);
          }
          while (r > y) {
            erase(b[r--]);
          }

          if (n - 1 - last[0] < z) {
            ans[k] = -1;
            continue;
          }

          ans[k] = INT_MAX;
          for (int u = last[0] + 1; u + z <= n; ++u) {
            ans[k] = min(ans[k], values[u + z - 1] - values[u]);
          }
        }
      }

      while (l <= r) {
        erase(b[l++]);
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    if (queries[i][0] != -1) {
      cout << ans[i] << "\n";
    }
  }
}