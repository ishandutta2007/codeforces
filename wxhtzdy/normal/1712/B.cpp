#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    for (int i = n - 1; i >= 1; i -= 2) {
      swap(p[i], p[i - 1]);
    }
    for (int i = 0; i < n; i++) {
      cout << p[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}