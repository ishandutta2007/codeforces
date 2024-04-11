#include <bits/stdc++.h>
using namespace std;

vector<array<int, 2>> ans;

void solve(int l, int r) {
  if (l + 1 == r) {
    return;
  }

  int m = (l + r) / 2;
  solve(l, m);
  solve(m, r);

  for (int i = 0; i < m - l; ++i) {
    ans.push_back({l + i, m + i});
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int gap = 1;
  while (gap * 2 <= n) {
    gap *= 2;
  }

  solve(1, 1 + gap);
  solve(n - gap + 1, n + 1);

  cout << ans.size() << "\n";
  for (auto [x, y] : ans) {
    cout << x << " " << y << "\n";
  }
}