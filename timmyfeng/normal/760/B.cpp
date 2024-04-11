#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, m, k;
  cin >> n >> m >> k;
  m -= n;

  long long lo = 0;
  long long hi = m;

  while (lo < hi) {
    long long mid = (lo + hi + 1) / 2;
    long long need = -mid;
    if (mid <= k) {
      need += mid * (mid + 1) / 2;
    } else {
      need += (mid + mid - k + 1) * k / 2;
    }
    if (mid <= n - k + 1) {
      need += mid * (mid + 1) / 2;
    } else {
      need += (mid + mid - n + k) * (n - k + 1) / 2;
    }

    if (need <= m) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }

  cout << lo + 1 << "\n";
}