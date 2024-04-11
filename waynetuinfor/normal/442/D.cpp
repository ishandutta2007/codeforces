#include <bits/stdc++.h>
using namespace std;

struct Info {
  pair<int, int> a, b;

  Info() : a{-1, -1}, b{-1, -1} {}

  void Update(int x, int y) {
    if (a.second == x) {
      a.first = y;
      return;
    }
    if (b.second == x) {
      b.first = y;
      if (a < b) swap(a, b);
      return;
    }
    pair<int, int> p{y, x};
    if (p > a) {
      b = a;
      a = p;
    } else if (p > b) {
      b = p;
    }
  }

  int Eval(bool r) const {
    return max(r + b.first, a.first);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n + 1, -1);
  vector<int> dp(n + 1, 1);
  vector<Info> info(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    p[i]--;
    int x = i;
    while (x > 0) {
      info[p[x]].Update(x, dp[x]);
      if (info[p[x]].Eval(p[x] > 0) == dp[p[x]]) break;
      dp[p[x]] = info[p[x]].Eval(p[x] > 0);
      x = p[x];
    }
    cout << dp[0] << " ";
  }
}