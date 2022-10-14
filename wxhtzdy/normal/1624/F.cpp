#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto Ask = [&](int x) {
    cout << "+ " << x << endl;
    int ret;
    cin >> ret;
    return ret;
  };
  function<int(int, int, int)> Dfs = [&](int l, int r, int c) {
    if (l + 1 == r) {
      return c * n + l;
    }
    int mid = l + r >> 1;
    int cc = Ask(n - mid);
    if (cc > c) {
      l = 0;
      r -= mid;
    } else {
      l += (n - mid);
      r = n;
    }
    return Dfs(l, r, cc);
  };
  int res = Dfs(1, n, 0);
  cout << "! " << res << endl;
  return 0;
}