#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (ans + 1 <= a[i]) {
      ++ans;
    }
  }

  cout << ans << "\n";
}