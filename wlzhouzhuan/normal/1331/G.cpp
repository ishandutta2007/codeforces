#include <bits/stdc++.h>
using namespace std;

int a[15];

int main() {
  for (int i = 0; i <= 10; i++) {
    cin >> a[i];
  }
  cout << fixed << setprecision(2);
  for (int i = 10; i >= 0; i--) {
    int v = a[i];
    double a = sqrt(abs(v));
    double b = v * v * v * 5;
    double res = a + b;
    if (res > 400) cout << "f(" << v << ") = MAGNA NIMIS!" << '\n';
    else cout << "f(" << v << ") = " << res << '\n';
  }
  return 0;
}