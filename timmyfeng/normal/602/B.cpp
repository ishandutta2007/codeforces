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

  int ans = 0;
  multiset<int> values;
  for (int i = 0, j = 0; i < n; ++i) {
    for ( ; j < n; ++j) {
      values.insert(a[j]);
      if (*(--values.end()) - *values.begin() > 1) {
        values.erase(a[j]);
        break;
      }
    }
    ans = max(ans, j - i);
    values.erase(values.find(a[i]));
  }

  cout << ans << "\n";
}