#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;
  int a = a1 + a2 + a3;
  int b1, b2, b3;
  cin >> b1 >> b2 >> b3;
  int b = b1 + b2 + b3;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    if (a * 2 >= b) {
      a -= 5;
    } else {
      b -= 10;
    }
  }
  if (a <= 0 && b <= 0) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}