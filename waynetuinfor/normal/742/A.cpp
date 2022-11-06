#include <iostream>
using namespace std;

int n;

int main() {
  cin >> n;
  int a = 1378;
  int ans = 1;
  for (; n; n /= 2) {
    if (n & 1) ans *= a, ans %= 10;
    a *= a; a %= 10;
  }
  cout << ans % 10 << '\n';
  return 0;
}