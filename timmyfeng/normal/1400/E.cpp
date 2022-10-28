#include <bits/stdc++.h>
using namespace std;

const int N = 5000;

int a[N];

int solve(int l, int r) {
  if (l > r) {
    return 0;
  }

  int mn = *min_element(a + l, a + r + 1);
  for (int i = l; i <= r; ++i) {
    a[i] -= mn;
  }

  int pre = l;
  int sum = mn;
  for (int i = l; i <= r; ++i) {
    if (a[i] == 0) {
      sum += solve(pre, i - 1);
      pre = i + 1;
    }
  }
  sum += solve(pre, r);
  return min(sum, r - l + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(0, n - 1) << "\n";
}