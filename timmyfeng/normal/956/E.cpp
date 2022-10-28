#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l, r;
  cin >> n >> l >> r;

  int sum = 0;
  vector<array<int, 2>> box(n);
  for (auto& i : box) {
    cin >> i[0];
    sum += i[0];
  }

  for (auto& i : box) {
    cin >> i[1];
  }

  if (sum < l) {
    cout << 0 << "\n";
    exit(0);
  }

  r = sum - min(sum, r);
  l = sum - l;
  swap(l, r);

  sort(box.begin(), box.end(), [](array<int, 2> a, array<int, 2> b) {
    if (a[1] == b[1]) {
      return a[0] > b[0];
    }
    return a[1] < b[1];
  });

  vector<int> dp(sum + 1, INT_MIN);
  dp[0] = 0;

  for (auto [a, b] : box) {
    for (int i = sum - a; i >= 0; --i) {
      dp[i + a] = max(dp[i + a], dp[i] + (b == 1 && i + a >= l && i + a <= r));
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << "\n";
}