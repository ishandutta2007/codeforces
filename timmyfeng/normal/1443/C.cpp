#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<array<int, 2>> dishes(n);
    for (int i = 0; i < 2; ++i) {
      for (auto &j : dishes) {
        cin >> j[i];
      }
    }

    long long lo = 0;
    long long hi = INT_MAX;

    while (lo < hi) {
      long long ans = (lo + hi) / 2;
      long long sum = 0;
      for (auto [a, b] : dishes) {
        if (a > ans) {
          sum += b;
        }
      }

      if (sum <= ans) {
        hi = ans;
      } else {
        lo = ans + 1;
      }
    }

    cout << lo << "\n";
  }
}