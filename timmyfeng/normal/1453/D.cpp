#include <bits/stdc++.h>
using namespace std;

const int L = 60;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 2 == 1) {
      cout << -1 << "\n";
      continue;
    }

    n /= 2;
    vector<int> ans;
    for (int i = L - 1; i > 0; --i) {
      while ((1LL << i) - 1 <= n) {
        n -= (1LL << i) - 1;
        for (int j = 0; j < i; ++j) {
          ans.push_back(j == 0);
        }
      }
    }

    cout << ans.size() << "\n";
    for (auto i : ans) {
      cout << i << " ";
    }
    cout << "\n";
  }
}