#include <iostream>
using namespace std;

int n, m, a[105], tot, l, r, pf[105];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i], pf[i] = pf[i - 1] + a[i];
  while (m--) {
    cin >> l >> r;
    if (pf[r] - pf[l - 1] > 0) tot += pf[r] - pf[l - 1];
  }
  cout << tot << '\n';
  return 0;
}