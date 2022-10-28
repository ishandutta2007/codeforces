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
    int one = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      one += (a == 1);
    }

    if (n / 2 % 2 == 0) {
      cout << n / 2 << "\n";
      for (int i = 0; i < n / 2; ++i) {
        cout << (one >= n / 2) << " ";
      }
      cout << "\n";
    } else {
      if (one <= n / 2) {
        cout << n / 2 << "\n";
        for (int i=  0; i < n / 2; ++i) {
          cout << 0 << " ";
        }
      } else {
        cout << n / 2 + 1 << "\n";
        for (int i = 0; i < n / 2 + 1; ++i) {
          cout << 1 << " ";
        }
      }
      cout << "\n";
    }
  }
}