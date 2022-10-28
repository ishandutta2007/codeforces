#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }

  int last = -1;
  map<int, vector<int>> c;
  for (int i = 0; i < m; ++i) {
    cin >> last;
    c[last].push_back(i);
  }

  int index = 0;
  while (index < n && (b[index] != last || a[index] == last)) {
    ++index;
  }

  if (index == n) {
    index = find(b.begin(), b.end(), last) - b.begin();
  }

  if (index == n) {
    cout << "NO\n";
    return;
  }

  vector<int> ans(m);
  ans[m - 1] = index;
  c[last].pop_back();
  a[index] = last;

  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      if (c[b[i]].empty()) {
        cout << "NO\n";
        return;
      }
      ans[c[b[i]].back()] = i;
      c[b[i]].pop_back();
    }
  }

  for (auto &i : c) {
    for (auto j : i.second) {
      ans[j] = ans[m - 1];
    }
  }

  cout << "YES\n";
  for (auto i : ans) {
    cout << i + 1 << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}