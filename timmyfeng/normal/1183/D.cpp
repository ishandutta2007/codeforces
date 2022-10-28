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
    vector<int> freq(n);
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      ++freq[a - 1];
    }
    sort(freq.rbegin(), freq.rend());
    int ans = 0;
    int prv = n + 1;
    for (auto i : freq) {
      prv = min(prv - 1, i);
      ans += max(0, prv);
    }
    cout << ans << "\n";
  }
}