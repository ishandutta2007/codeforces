#include <bits/stdc++.h>
using namespace std;

const int N = 300;

int farthest[N][N], length[N][N][N], points[N];
array<int, 2> light[N];

void set_max(int &a, int b) {
  if (b > a) {
    a = b;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int a, l;
    cin >> a >> l;
    light[i] = {a, l};

    points[3 * i] = a - l;
    points[3 * i + 1] = a;
    points[3 * i + 2] = a + l;
  }

  sort(light, light + n);
  sort(points, points + 3 * n);
  int m = unique(points, points + 3 * n) - points;

  for (int i = 0; i < n; ++i) {
    farthest[i][i] = -1;
    for (int j = i - 1; j >= 0; --j) {
      int w = find(points, points + m, light[j][0] + light[j][1]) - points;
      farthest[j][i] = max(farthest[j + 1][i], w);
    }
  }

  for (int i = 0; i < n; ++i) {
    int u = find(points, points + m, light[i][0] - light[i][1]) - points;
    int v = find(points, points + m, light[i][0] + light[i][1]) - points;
    int w = find(points, points + m, light[i][0]) - points;

    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k < m; ++k) {
        for (int l = k; l < m; ++l) {
          if (l <= w && k <= u) {
            int r = max(w, farthest[j][i]);
            if (l < u) {
              set_max(length[i + 1][u][r], length[j][k][l] + points[r] - points[u]);
            } else {
              set_max(length[i + 1][k][r], length[j][k][l] + points[r] - points[l]);
            }
          }

          if (l <= v && k <= w) {
            if (l < w) {
              set_max(length[i + 1][w][v], length[j][k][l] + points[v] - points[w]);
            } else {
              set_max(length[i + 1][k][v], length[j][k][l] + points[v] - points[l]);
            }
          }
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = j; k < m; ++k) {
        set_max(ans, length[i][j][k]);
      }
    }
  }

  cout << ans << "\n";
}