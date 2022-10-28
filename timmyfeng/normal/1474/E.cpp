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

    vector<int> perm(n + 1);
    iota(perm.begin(), perm.end(), 0);
    vector<array<int, 2>> ans;

    for (int i = 1; i <= n / 2; ++i) {
      ans.push_back({i, n});
      swap(perm[i], perm[n]);
    }

    for (int i = n / 2 + 1; i < n; ++i) {
      ans.push_back({i, 1});
      swap(perm[i], perm[1]);
    }

    long long time = 0;
    reverse(ans.begin(), ans.end());
    for (auto [a, b] : ans) {
      time += (long long) (b - a) * (b - a);
    }

    cout << time << "\n";
    for (int i = 1; i <= n; ++i) {
      cout << perm[i] << " ";
    }
    cout << "\n";
    cout << ans.size() << "\n";
    for (auto [a, b] : ans) {
      cout << a << " " << b << "\n";
    }
  }
}