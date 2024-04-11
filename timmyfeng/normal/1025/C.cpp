#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  s += s;

  char prv = 0;
  int cur = 0, ans = 0;
  for (auto c : s) {
    if (c == prv) {
      cur = 1;
    } else {
      prv = c;
      ++cur;
    }
    ans = max(ans, cur);
  }

  cout << min((int) s.size() / 2, ans) << "\n";
}