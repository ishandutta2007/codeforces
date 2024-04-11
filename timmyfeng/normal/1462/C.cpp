#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;

    int ans = INT_MAX;
    for (int i = 0; i < (1 << 9); ++i) {
      int sum = 0, number = 0;
      for (int j = 0; j < 9; ++j) {
        if (i & (1 << j)) {
          sum += j + 1;
          number = number * 10 + j + 1;
        }
      }

      if (sum == a) {
        ans = min(ans, number);
      }
    }
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
  }
}