#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, d, b;
  cin >> n >> d >> b;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int lo = 0;
  int hi = n / 2;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    int cur = mid;
    int cnt = b;
    for (int i = 0; i < n; ++i) {
      int used = 0;
      while (used < a[i]) {
        int t = (cur == i) ? 0 : (abs(cur - i) - 1) / d + 1;
        if (t > min(cur + 1, n - cur)) {
          break;
        }

        if (used + cnt <= a[i]) {
          used += cnt;
          cnt = b;
          ++cur;
        } else {
          int remain = a[i] - used;
          used += remain;
          cnt -= remain;
        }
      }
    }

    if (n - cur <= mid) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << lo << "\n";
}