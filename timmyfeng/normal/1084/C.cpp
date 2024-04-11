#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
  return (a += b) < MOD ? a : a - MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int ans = 0;
  int cur = 1;
  int pending = 0;
  for (char c : s) {
    if (c == 'a') {
      ans = add(ans, cur);
      pending = add(pending, cur);
    } else if (c == 'b') {
      cur = add(cur, pending);
      pending = 0;
    }
  }

  cout << ans << "\n";
}