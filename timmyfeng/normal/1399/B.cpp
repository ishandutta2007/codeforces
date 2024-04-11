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
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    vector<int> b(n);
    for (auto& i : b) {
      cin >> i;
    }

    long long ans = 0;
    int mn_a = *min_element(a.begin(), a.end());
    int mn_b = *min_element(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
      ans += max(a[i] - mn_a, b[i] - mn_b);
    }

    cout << ans << "\n";
  }
}