#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, m;
  cin >> n >> m;
  if (n > m) {
    swap(n, m);
  }

  if (m < 3) {
    cout << 0 << "\n";
  } else if (n == 1) {
    cout << m - m % 6 + max(0LL, (m % 6 - 3) * 2) << "\n";
  } else if (n == 2) {
    cout << (m == 3 || m == 7 ? 2 * m - 2 : 2 * m) << "\n";
  } else {
    cout << n * m - (n % 2) * (m % 2) << "\n";
  }
}