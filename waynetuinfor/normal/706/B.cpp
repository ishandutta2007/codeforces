#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5;
int x[maxn], m, n, q;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i];
  sort(x, x + n);
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> m;
    cout << upper_bound(x, x + n, m) - x << '\n';
  }
  return 0;
}