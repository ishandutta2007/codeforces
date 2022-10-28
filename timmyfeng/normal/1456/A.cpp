#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    string s;
    int n, p, k, x, y;
    cin >> n >> p >> k >> s >> x >> y;

    int ans = INT_MAX;
    vector<int> count(n);
    for (int i = n - 1; i >= p - 1; --i) {
      count[i] = (s[i] == '0');
      if (i + k < n) {
        count[i] += count[i + k];
      }
      ans = min(ans, y * (i - p + 1) + x * count[i]);
    }

    cout << ans << "\n";
  }
}