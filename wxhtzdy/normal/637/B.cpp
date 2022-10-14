#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<string, int> was;
  for (int i = n - 1; i >= 0; i--) {
    if (!was[a[i]]) {
      cout << a[i] << '\n';
      was[a[i]] = 1;
    }
  }
  return 0;
}