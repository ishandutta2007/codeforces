#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;

    if (a - b > 1) {
      cout << "NO\n";
    } else {
      long long c = a + b;
      bool prime = true;
      for (long long i = 2; i * i <= c; ++i) {
        prime &= (c % i != 0);
      }
      cout << (prime ? "YES" : "NO") << "\n";
    }
  }
}