#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "-1\n";
    } else {
      for (int i = 0; i < n - 1; ++i) cout << 3;
      cout << 4 << "\n";
    }
  }
}