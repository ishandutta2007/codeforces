#include <bits/stdc++.h>

using namespace std;

int main() {
  int nTest;
  cin >> nTest;

  while (nTest--) {
    string a, b, c;
    cin >> a >> b >> c;

    int n = a.length();

    bool ok = true;
    for(int i = 0; i < n; ++i) {
      if (!(a[i] == c[i] || b[i] == c[i])) {
        ok = false;
        break;
      }
    }

    puts(ok ? "YES" : "NO");
  }

  return 0;
}