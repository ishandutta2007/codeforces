#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sum = accumulate(a.begin(), a.end(), 0);
  cout << (x - sum == n - 1 ? "YES" : "NO") << '\n';
  return 0;
}