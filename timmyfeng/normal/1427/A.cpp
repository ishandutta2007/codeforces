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

    int sum = 0;
    vector<int> pos, neg, zero;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (a == 0) {
        zero.push_back(a);
      } else if (a > 0) {
        pos.push_back(a);
      } else {
        neg.push_back(a);
      }
      sum += a;
    }

    if (accumulate(pos.begin(), pos.end(), 0) < -accumulate(neg.begin(), neg.end(), 0)) {
      swap(pos, neg);
    }

    if (sum == 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto i : pos) {
        cout << i << " ";
      }
      for (auto j : neg) {
        cout << j << " ";
      }
      for (auto k : zero) {
        cout << k << " ";
      }
      cout << "\n";
    }
  }
}