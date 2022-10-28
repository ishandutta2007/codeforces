#include <bits/stdc++.h>
using namespace std;

vector<int> a, d;

void dfs(int l, int r, int x) {
  if (l == r)
    return;
  int m = max_element(a.begin() + l, a.begin() + r) - a.begin();
  d[m] = x;
  dfs(l, m, x + 1);
  dfs(m + 1, r, x + 1);
}

void solve() {
  int n;
  cin >> n;

  a.resize(n), d.resize(n);
  for (auto &i : a)
    cin >> i;

  dfs(0, n, 0);
  
  for (auto i : d)
    cout << i << " ";
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
    solve();
}