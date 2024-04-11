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
    if (n <= k) {
      cout << k - n << "\n";
    } else {
      cout << (n + k) % 2 << "\n";
    }
  }
}