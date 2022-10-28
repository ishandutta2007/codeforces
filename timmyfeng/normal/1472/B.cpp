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

    int one = 0, two = 0, total = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      total += a;
      ++(a == 1 ? one : two);
    }

    bool ans = false;
    for (int i = 0; i <= one; ++i) {
      for (int j = 0; j <= two; ++j) {
        ans |= (2 * i + 4 * j == total);
      }
    }

    cout << (ans ? "YES" : "NO") << "\n";
  }
}