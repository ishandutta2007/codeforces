#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    int sum = 0;
    int mini = INT_MAX;
    bool parity = false;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int a;
        cin >> a;
        sum += abs(a);
        parity ^= (a < 0);
        mini = min(mini, abs(a));
      }
    }

    cout << (parity ? sum - 2 * mini : sum) << "\n";
  }
}