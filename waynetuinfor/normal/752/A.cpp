#include <iostream>
using namespace std;

int n, m, k;
char c;

int main() {
  cin >> n >> m >> k;
  int l = k / (m * 2) + ((k % (m * 2)) ? 1 : 0);
  // k % (2 * m);
  k -= (l - 1) * 2 * m;
  int d;
  // if (k % (2 * m) == 0) d = k / (2 * m);
  // else k = k % (2 * m), d = k / 2 + (k & 1);
  d = k / 2 + (k & 1);
  c = k & 1 ? 'L' : 'R';
  cout << l << ' ' << d << ' ' << c << '\n';
  return 0;
}