#include <bits/stdc++.h>
using namespace std;

const long long A = 1000000000000000000LL;

long long mini[4], maxi[4], plane[4];
long long ans[4], rose[3];

bool solve(long long d, int k) {
  plane[3] = 0;
  for (int i = 0; i < 3; ++i) {
    plane[i] = mini[i] - d;
    plane[i] += (abs(plane[i] % 2) != k);
    if (plane[i] > maxi[i] + d) {
      return false;
    }
    plane[3] += plane[i];
  }

  for (int i = 0; i < 3 && plane[3] < mini[3] - d; ++i) {
    long long delta = min(
        maxi[i] + d - plane[i],
        mini[3] - d - plane[3] + 1
    );
    delta -= delta % 2;
    plane[i] += delta;
    plane[3] += delta;
  }

  return mini[3] - d <= plane[3] && plane[3] <= maxi[3] + d;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < 4; ++i) {
      mini[i] = LLONG_MIN;
      maxi[i] = LLONG_MAX;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 3; ++j) {
        cin >> rose[j];
      }

      for (int j = 0; j < 4; ++j) {
        long long sum = 0;
        for (int k = 0; k < 3; ++k) {
          if (j == k) {
            sum -= rose[k];
          } else {
            sum += rose[k];
          }
        }
        maxi[j] = min(maxi[j], sum);
        mini[j] = max(mini[j], sum);
      }
    }

    long long lo = 0, hi = 3 * A + 1;
    while (lo < hi) {
      long long mid = lo + (hi - lo) / 2;
      if (solve(mid, 0) || solve(mid, 1)) {
        copy(plane, plane + 4, ans);
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }

    for (int i = 0; i < 3; ++i) {
      cout << (ans[3] - ans[i]) / 2 << " ";
    }
    cout << "\n";
  }
}