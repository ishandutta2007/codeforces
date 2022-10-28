#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += s[i] == s[(i + 1) % n];
    }

    cout << ans / 2 << "\n";
  }
}