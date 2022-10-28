#include <bits/stdc++.h>
using namespace std;

const int X = 1000000;

bool visited[X];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long k, l, r, t, x, y;
  cin >> k >> l >> r >> t >> x >> y;
  k = k - l, l = r - l;

  if (k + y <= l) {
    k += y;
  }

  if (x > y) {
    k -= x;
    if (k >= 0 && t - 1 <= k / (x - y)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  } else {
    while (k / x < t) {
      t -= k / x;
      k %= x;

      if (visited[k]) {
        cout << "Yes\n";
        exit(0);
      }
      visited[k] = true;

      if (k + y > l) {
        cout << "No\n";
        exit(0);
      }
      k += y;
    }
    cout << "Yes\n";
  }
}