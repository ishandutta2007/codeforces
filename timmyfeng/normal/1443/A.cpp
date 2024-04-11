#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cout << 2 * (n + i) << " ";
    }
    cout << "\n";
  }
}