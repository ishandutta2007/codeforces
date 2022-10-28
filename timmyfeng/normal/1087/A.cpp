#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  string ans;
  int l = (s.size() - 1u) / 2;
  int r = (s.size() + 1u) / 2;
  while (ans.size() < s.size()) {
    if ((r - l) % 2 == 1) {
      ans += s[l];
      --l;
    } else {
      ans += s[r];
      ++r;
    }
  }
  cout << ans << "\n";
}