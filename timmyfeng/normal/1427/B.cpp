#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'W') {
        if (i > 0 && s[i - 1] == 'W') {
          ans += 2;
        } else {
          ans += 1;
        }
      }
    }

    if (ans == 0) {
      cout << max(0, 2 * min(n, k) - 1) << "\n";
      continue;
    }

    int start = 0;
    while (s[start] == 'L') {
      ++start;
    }

    int finish = 0;
    while (s[n - 1 - finish] == 'L') {
      ++finish;
    }

    vector<int> gaps;
    for (int i = start + 1, j = 0; i < n; ++i) {
      if (s[i] == 'L') {
        ++j;
      } else {
        gaps.push_back(j);
        j = 0;
      }
    }

    sort(gaps.begin(), gaps.end());
    for (auto i : gaps) {
      if (i == 0) {
        continue;
      }
      if (k < i) {
        ans += 2 * k;
        k = 0;
      } else {
        ans += 2 * i + 1;
        k -= i;
      }
    }

    ans += min(start + finish, k) * 2;

    cout << ans << "\n";
  }
}