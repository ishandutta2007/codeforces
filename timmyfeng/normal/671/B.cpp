#include <bits/stdc++.h>
using namespace std;

const int N = 500000;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n, greater<int>());

  long long dist = 0;
  for (int i = 0; i < n; ++i) {
    dist += abs(sum / n + (i < sum % n) - a[i]);
  }
  dist /= 2;

  if (k >= dist) {
    cout << (sum % n > 0) << "\n";
    exit(0);
  }

  int lo = a[n - 1], hi = sum / n;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    long long need = 0;
    for (int i = 0; i < n; ++i) {
      need += max(0, mid - a[i]);
    }

    if (need > k) {
      hi = mid - 1;
    } else {
      lo = mid;
    }
  }
  int ans = -lo;

  lo = sum / n, hi = a[0];
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    long long need = 0;
    for (int i = 0; i < n; ++i) {
      need += max(0, a[i] - mid);
    }

    if (need > k) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  ans += lo;

  cout << ans << "\n";
}