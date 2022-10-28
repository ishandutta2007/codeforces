#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;

int pre_min[N], pre_max[N], suf_min[N], suf_max[N], n;
array<int, 2> point[N];

long long calc(int i, int j) {
  if (i == 0 && j == n) {
    return 0;
  }

  int min_y = min(pre_min[i], suf_min[j]);
  int max_y = max(pre_max[i], suf_max[j]);
  long long dy = max_y - min_y;

  long long x = max(abs(point[i][0]), abs(point[j - 1][0]));
  long long y = max(abs(min_y), abs(max_y));

  return max(dy * dy, x * x + y * y);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (auto &j : point[i]) {
      cin >> j;
    }
  }
  sort(point, point + n);

  pre_min[0] = suf_min[n] = INT_MAX;
  pre_max[0] = suf_max[n] = INT_MIN;

  for (int i = 0; i < n; ++i) {
    pre_min[i + 1] = min(pre_min[i], point[i][1]);
    pre_max[i + 1] = max(pre_max[i], point[i][1]);
  }

  for (int i = n - 1; i >= 0; --i) {
    suf_min[i] = min(suf_min[i + 1], point[i][1]);
    suf_max[i] = max(suf_max[i + 1], point[i][1]);
  }

  long long l = 0, r = LLONG_MAX;
  for (int k = 0; k < 2; ++k) {
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; ++i) {
      mini = min(mini, point[i][k]);
      maxi = max(maxi, point[i][k]);
    }
    long long delta = maxi - mini;
    r = min(r, delta * delta);
  }

  while (l < r) {
    long long d = (l + r) / 2;
    bool ok = false;

    for (int i = 0, j = 0; i < n && point[i][0] <= 0; ++i) {
      for ( ; j > i && point[j - 1][0] > -point[i][0]; --j);
      for ( ; j < n && point[j][0] <= -point[i][0]; ++j) {
        long long dx = point[j][0] - point[i][0];
        if (dx * dx > d) {
          break;
        }
      }
      ok |= (calc(i, j) <= d);
    }

    for (int i = n - 1, j = n - 1; i >= 0 && point[i][0] > 0; --i) {
      for ( ; j < i && -point[j + 1][0] > point[i][0]; ++j);
      for ( ; j >= 0 && -point[j][0] <= point[i][0]; --j) {
        long long dx = point[j][0] - point[i][0];
        if (dx * dx > d) {
          break;
        }
      }
      ok |= (calc(j + 1, i + 1) <= d);
    }

    if (ok) {
      r = d;
    } else {
      l = d + 1;
    }
  }

  cout << l << "\n";
}