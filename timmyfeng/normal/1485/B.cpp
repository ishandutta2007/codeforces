#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q, k;
  cin >> n >> q >> k;

  vector<long long> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << a[r] - a[l] - 2 * r + 2 * l + k - 1 << "\n";
  }
}