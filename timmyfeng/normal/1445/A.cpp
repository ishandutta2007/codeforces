#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());

  vector<int> b(n);
  for (auto &i : b) {
    cin >> i;
  }
  sort(b.rbegin(), b.rend());

  for (int i = 0; i < n; ++i) {
    if (a[i] + b[i] > x) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
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