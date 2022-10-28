#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int a, b;
    string s;
    cin >> a >> b >> s;

    int n = s.size();
    int r = n - 1;
    int l = 0;

    while (l < n && s[l] == '0') {
      ++l;
    }

    while (r >= 0 && s[r] == '0') {
      --r;
    }

    if (l > r) {
      cout << 0 << "\n";
      continue;
    }

    vector<int> edges;
    int length = 0;

    for (int i = l; i <= r; ++i) {
      if (s[i] == '1') {
        if (length != 0) {
          edges.push_back(length);
          length = 0;
        }
      } else {
        ++length;
      }
    }

    sort(edges.begin(), edges.end());
    int sum = (edges.size() + 1) * a;
    int ans = sum;

    for (auto i : edges) {
      sum += i * b - a;
      ans = min(ans, sum);
    }

    cout << ans << "\n";
  }
}