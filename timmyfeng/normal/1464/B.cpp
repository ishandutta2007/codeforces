#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  long long x, y;
  cin >> s >> x >> y;

  if (x > y) {
    reverse(s.begin(), s.end());
    swap(x, y);
  }

  long long sum = 0;
  int l0 = 0, l1 = 0;
  for (auto c : s) {
    if (c == '0' || c == '?') {
      sum += y * l1;
      ++l0;
    } else {
      sum += x * l0;
      ++l1;
    }
  }

  int r0 = 0, r1 = 0;
  long long ans = sum;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == '?') {
      --l0;
      sum -= x * r1 + y * l1;
      sum += x * l0 + y * r0;
      ans = min(ans, sum);
      ++r1;
    } else if (s[i] == '0') {
      --l0, ++r0;
    } else if (s[i] == '1') {
      --l1, ++r1;
    }
  }

  cout << ans << "\n";
}