#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> segments;
    while (!s.empty()) {
      char cur = s.back();
      int len = 0;
      while (!s.empty() && s.back() == cur) {
        s.pop_back();
        ++len;
      }

      if (cur == '1') {
        segments.push_back(len);
      }
    }

    sort(segments.rbegin(), segments.rend());
    int ans = 0;
    for (int i = 0; i < segments.size(); i += 2) {
      ans += segments[i];
    }
    cout << ans << "\n";
  }
}