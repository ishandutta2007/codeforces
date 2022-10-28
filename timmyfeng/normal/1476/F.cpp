#include <bits/stdc++.h>
using namespace std;

const int N = 300000 + 1;
const int L = __lg(N) + 1;

int p[N], light[N], sparse[L][N];

int query(int a, int b) {
  int l = __lg(b - a);
  return max(sparse[l][a], sparse[l][b - (1 << l)]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }

    for (int i = 0; i <= __lg(n); ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        if (i == 0) {
          sparse[i][j] = min(n - 1, j + p[j]);
        } else {
          sparse[i][j] = max(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      light[i + 1] = light[i];
      if (light[i] > i) {
        light[i + 1] = max(light[i + 1], min(n, i + p[i] + 1));
      }

      int j = lower_bound(light, light + i + 1, i - p[i]) - light;
      if (j == i) {
        light[i + 1] = max(light[i + 1], i);
      } else if (j < i) {
        light[i + 1] = max(light[i + 1], query(j, i) + 1);
      }
    }

    if (light[n] == n) {
      cout << "YES\n";

      int i = n - 1;
      string ans(n, 'R');
      while (i > 0) {
        if (light[i] > i && light[i + 1] == max(light[i], min(n, i + p[i] + 1))) {
          --i;
        } else {
          ans[i] = 'L';
          i = lower_bound(light, light + i + 1, i - p[i]) - light - 1;
        }
      }
      cout << ans << "\n";
    } else {
      cout << "NO\n";
    }
  }
}