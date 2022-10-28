#include <bits/stdc++.h>
using namespace std;

const int N = 1'500 + 1;

int best[N][N];
int sum[N];

array<int, 2> segment[N];
int n, s, m, k;
int a[N];

int solve(int key) {
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = (a[i] <= key) + sum[i];
  }

  int ans = 0;
  for (int i = 0, k = 0; i < s; ++i) {
    while (segment[k][1] <= segment[i][0]) {
      ++k;
    }

    for (int j = 1; j <= m; ++j) {
      best[i + 1][j] = max(best[i][j], best[k][j - 1] + sum[segment[i][1]] - sum[segment[i][0]]);
      if (k < i) {
        best[i + 1][j] = max(best[i + 1][j], best[k + 1][j - 1] + sum[segment[i][1]] - sum[segment[k][1]]);
      }
    }

    ans = max(ans, best[i + 1][m]);
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> s >> m >> k;

  int max_a = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    max_a = max(max_a, a[i]);
  }

  for (int i = 0; i < s; ++i) {
    for (auto &j : segment[i]) {
      cin >> j;
    }
    --segment[i][0];
  }
  sort(segment, segment + s);

  for (int i = s - 1; i > 0; --i) {
    if (segment[i][1] <= segment[i - 1][1]) {
      for (int j = i; j < s - 1; ++j) {
        segment[j] = segment[j + 1];
      }
      --s;
    }
  }

  int hi = max_a + 1;
  int lo = 0;

  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (solve(mid) >= k) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  if (lo > max_a) {
    cout << -1 << "\n";
    exit(0);
  }

  cout << lo << "\n";
}