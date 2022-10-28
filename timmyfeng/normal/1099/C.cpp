#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  string s;
  cin >> s >> k;

  string ans;
  int cur = int(s.size()) -
      count(s.begin(), s.end(), '*') -
      count(s.begin(), s.end(), '?');

  for (auto i : s) {
    if (i == '*' || i == '?') {
      if (cur > k) {
        ans.pop_back();
        --cur;
      }
      while (cur < k && i == '*') {
        ans += ans.back();
        ++cur;
      }
    } else {
      ans += i;
    }
  }

  if (cur == k) {
    cout << ans << "\n";
  } else {
    cout << "Impossible\n";
  }
}