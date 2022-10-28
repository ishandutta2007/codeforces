#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    while (true) {
      bool ok = true;
      long long m = n;
      while (m > 0) {
        if (m % 10 > 0) {
          ok &= (n % (m % 10) == 0);
        }
        m /= 10;
      }

      if (ok) {
        break;
      }
      ++n;
    }
    cout << n << "\n";
  }
}