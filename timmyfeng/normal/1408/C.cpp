#include <bits/stdc++.h>
using namespace std;

const int N = 100'000 + 1;

int diff[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(12);

  int t;
  cin >> t;

  while (t--) {
    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    diff[0] = a[0];
    for (int i = 1; i < n; ++i) {
      diff[i] = a[i] - a[i - 1];
    }
    diff[n] = l - a[n - 1];

    double lo = 0.0;
    double hi = l;

    for (int i = 0; i < 64; ++i) {
      double mid = (lo + hi) / 2;
      double sum = 0.0;

      for (int j = 0; j < 2; ++j) {
        double t = 0.0;
        for (int v = 0; v <= n + 1; ++v) {
          if (v <= n && t + (double) diff[v] / (v + 1) <= mid) {
            t += (double) diff[v] / (v + 1);
            sum += diff[v];
          } else {
            sum += (v + 1) * (mid - t);
            break;
          }
        }
        reverse(diff, diff + n + 1);
      }

      (sum < l ? lo : hi) = mid;
    }

    cout << lo << "\n";
  }
}