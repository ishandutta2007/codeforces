#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, a, b, c, d;
  cin >> n >> k >> a >> b >> c >> d;

  if (k <= n || n == 4) {
    cout << -1 << "\n";
    exit(0);
  }

  cout << a << " " << c << " ";
  for (int i = 1; i <= n; ++i) {
    if (i != a && i != b && i != c && i != d) {
      cout << i << " ";
    }
  }
  cout << d << " " << b << "\n";

  cout << c << " " << a << " ";
  for (int i = 1; i <= n; ++i) {
    if (i != a && i != b && i != c && i != d) {
      cout << i << " ";
    }
  }
  cout << b << " " << d << "\n";
}