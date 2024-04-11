#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    if (n % 2 == 1) {
      bool ok = false;
      for (int i = 0; i < n; i += 2) {
        ok |= (s[i] % 2 == 1);
      }
      cout << 2 - ok << "\n";
    } else {
      bool ok = false;
      for (int i = 1; i < n; i += 2) {
        ok |= (s[i] % 2 == 0);
      }
      cout << 1 + ok << "\n";
    }
  }
}