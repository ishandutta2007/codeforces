#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n), ans(n);
  vector<array<int, 2>> b(n);
  for (auto& i : a) {
    cin >> i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i][0];
    b[i][1] = i;
  }
  sort(a.rbegin(), a.rend());
  sort(b.begin(), b.end());
  for (int i = 0; i < n; ++i) {
    ans[b[i][1]] = a[i];
  }
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}