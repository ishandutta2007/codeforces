#include <bits/stdc++.h>
using namespace std;

const int N = 2'000 + 1;
const int K = 1'000'000;

int a[K];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;
  cin >> t >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] -= t;
  }

  sort(a, a + n);
  n = unique(a, a + n) - a;

  bitset<N> dp;
  dp[N / 2] = 1;
  for (int i = 1; i < N; ++i) {
    bitset<N> dp_new;
    for (int j = 0; j < n; ++j) { 
      if (a[j] < 0) {
        dp_new |= dp >> (-a[j]);
      } else if (a[j] > 0) {
        dp_new |= dp << a[j];
      } else {
        dp_new |= dp;
      }
    }
    dp = dp_new;

    if (dp[N / 2] == 1) {
      cout << i << "\n";
      exit(0);
    }
  }

  cout << -1 << "\n";
}