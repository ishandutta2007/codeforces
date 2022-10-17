#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int64_t x;
  cin >> n >> x;
  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }
  for (int i = 0; i < n; ++i) d.push_back(d[i]);
  int64_t res = 0;
  int64_t sum = 0;
  int64_t val = 0;
  for (int i = 0, j = 0; i < n + n; ++i) {
    sum += d[i];
    val += 1LL * d[i] * (d[i] + 1) / 2;
    while (j <= i && sum > x) {
      sum -= d[j];
      val -= 1LL * d[j] * (d[j] + 1) / 2;
      j++;
    }
    if (i >= n) {
      int rem = x - sum;
      int p = (j + n - 1) % n;
      assert(sum + d[p] > x);
      int l = d[p] - rem + 1;
      int64_t g = 1LL * (d[p] + l) * (d[p] - l + 1) / 2;
      res = max(res, val + g);
    }
  }
  cout << res << "\n";
}