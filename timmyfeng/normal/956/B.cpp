#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, u;
  cin >> n >> u;

  vector<int> e(n);
  for (auto& i : e) {
    cin >> i;
  }

  int ptr = 0;
  double ans = -1.0;
  for (int i = 0; i < n - 2; ++i) {
    while (ptr + 1 < n && e[ptr + 1] - e[i] <= u) {
      ++ptr;
    }
    if (i + 2 <= ptr) {
      ans = max(ans, 1.0 * (e[ptr] - e[i + 1]) / (e[ptr] - e[i]));
    }
  }

  if (ans < 0) {
    cout << -1 << "\n";
  } else {
    cout << fixed << setprecision(12) << ans << "\n";
  }
}