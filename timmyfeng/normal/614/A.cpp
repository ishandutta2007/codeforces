#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long l, r, k;
  cin >> l >> r >> k;

  bool p = false;
  long long x = 1;
  do {
    if (x >= l && x <= r) {
      cout << x << " ";
      p = true;
    }
  } while (!__builtin_mul_overflow(x, k, &x));

  if (!p) {
    cout << -1 << " ";
  }

  cout << "\n";
}