#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    if (n % 2 == 0) {
      cout << (k - 1) % n + 1 << "\n";
    } else {
      cout << ((long long) (k - 1) / (n / 2) * (n / 2 + 1) + (k - 1) % (n / 2)) % n + 1 << "\n";
    }
  }
}