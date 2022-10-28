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

    cout << (n < k ? (k - 1) / n + 1 : 1 + (n % k != 0)) << "\n";
  }
}