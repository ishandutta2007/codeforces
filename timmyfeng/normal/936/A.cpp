#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long k, d, t;
  cin >> k >> d >> t;

  t *= 2;
  if (k % d == 0) {
    d = k;
  } else {
    d = k - k % d + d;
  }

  long long reps = t / (k + d);
  long long remain = t % (k + d);

  if (remain <= k * 2) {
    cout << fixed << setprecision(1) << d * reps + 1.0 * remain / 2 << "\n";
  } else {
    cout << d * reps + remain - k << "\n";
  }
}