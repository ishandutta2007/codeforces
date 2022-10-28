#include <bits/stdc++.h>
using namespace std;

long long cbrt(long long x) {
  long long l = 1, r = 100000;
  while (l < r) {
    long long m = (l + r + 1) / 2;
    if (m * m * m > x) {
      r = m - 1;
    } else {
      l = m;
    }
  }
  return l;
}

array<long long, 2> solve(long long x) {
  if (x == 0) {
    return {0, 0};
  }

  long long y = cbrt(x);
  array<long long, 2> ans = solve(x - y * y * y);
  ++ans[0], ans[1] += y * y * y;

  if (y > 0) {
    long long cb = (y - 1) * (y - 1) * (y - 1);
    array<long long, 2> oth = solve(y * y * y - 1 - cb);
    ++oth[0], oth[1] += cb;
    ans = max(ans, oth);
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long m;
  cin >> m;
  for (auto i : solve(m)) {
    cout << i << " ";
  }
  cout << "\n";
}