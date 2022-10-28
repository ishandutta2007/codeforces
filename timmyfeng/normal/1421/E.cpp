#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int indices[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ans += a[i];
  }

  if (n == 1) {
    cout << a[0] << "\n";
    exit(0);
  }

  iota(indices, indices + n, 0);
  sort(indices, indices + n, [&](int i, int j) {
    return a[i] < a[j];
  });

  int flip = 0;
  if (n % 3 != 1) {
    ans -= 2 * a[indices[flip++]];
    if (n % 3 == 2) {
      ans -= 2 * a[indices[flip++]];
    }
  }

  for ( ; flip + 3 <= n; flip += 3) {
    long long delta = 0;
    for (int i = flip; i < flip + 3; ++i) {
      delta += a[indices[i]];
    }
    if (delta < 0) {
      ans -= 2 * delta;
    } else {
      break;
    }
  }

  if (n % 2 == 1 && flip == n / 2) {
    bool odd = true;
    for (int i = 0; i < flip; ++i) {
      odd &= (indices[i] % 2 == 1);
    }

    if (odd) {
      sort(a, a + n);
      long long move = ans - 2 * (a[n / 2] - a[n / 2 - 1]);
      long long remove = (flip >= 3 ? -accumulate(a, a + flip - 3, 0LL) + accumulate(a + flip - 3, a + n, 0LL) : LLONG_MIN);
      long long add = (flip + 3 <= n ? -accumulate(a, a + flip + 3, 0LL) + accumulate(a + flip + 3, a + n, 0LL) : LLONG_MIN);
      ans = max({move, remove, add});
    }
  }

  cout << ans << "\n";
}