#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int a, b, k;
    cin >> a >> b >> k;

    long long ans = (long long) k * (k - 1) / 2;

    vector<array<int, 2>> pairs(k);
    for (int i = 0; i < k; ++i) {
      cin >> pairs[i][0];
    }

    for (int i = 0; i < k; ++i) {
      cin >> pairs[i][1];
    }

    map<int, int> boy, girl;
    map<array<int, 2>, int> couple;
    for (auto &i : pairs) {
      ++boy[i[0]];
      ++girl[i[1]];
      ++couple[i];
    }

    for (auto [i, j] : boy) {
      ans -= (long long) j * (j - 1) / 2;
    }

    for (auto [i, j] : girl) {
      ans -= (long long) j * (j - 1) / 2;
    }

    for (auto [i, j] : couple) {
      ans += (long long) j * (j - 1) / 2;
    }

    cout << ans << "\n";
  }
}