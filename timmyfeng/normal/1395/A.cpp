#include <bits/stdc++.h>
using namespace std;

int a[4];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    for (int& i : a) {
      cin >> i;
    }

    bool ok = false;
    for (int k = 0; k < 2; ++k) {
      int cnt = 0;
      for (int i : a) {
        cnt += i % 2;
      }
      ok |= (cnt <= 1);

      if (*min_element(a, a + 3) >= 1) {
        for (int i = 0; i < 3; ++i) {
          --a[i];
        }
        a[3] += 3;
      }
    }

    cout << (ok ? "Yes" : "No") << "\n";
  }
}