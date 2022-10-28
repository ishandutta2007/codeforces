#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
const double E = 1e-12;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(12);

  int n, m;
  cin >> n >> m;

  double ans = m;
  for (int i = 0; i < 2 * n; ++i) {
    int a;
    cin >> a;
    if (a == 1) {
      cout << -1 << "\n";
      exit(0);
    }
    ans *= a / (a - 1.0);
  }

  cout << ans - m << "\n";
}