#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<long long> a(n), b(m);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());

  for (auto &j : b) {
    cin >> j;
  }

  long long gcd = 0;
  for (int i = 1; i < n; ++i) {
    gcd = __gcd(gcd, a[i] - a[i - 1]);
  }

  for (auto j : b) {
    cout << __gcd(gcd, a[0] + j) << " ";
  }
  cout << "\n";
}