#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l, v1, v2, k;
  cin >> n >> l >> v1 >> v2 >> k;
  n = (n + k - 1) / k;

  double a = n;
  double b = -n + 1;
  double c = v1 - v2;
  double d = v1 + v2;
  double y = -l * c / (a * d - b * c);

  cout << fixed << setprecision(8) << (l + 2 * (n - 1) * y) /  v2 << "\n";
}