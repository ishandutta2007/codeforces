#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, p;
  cin >> n >> p;
  for (int i = 1; n - 1LL * p * i > 0; ++i) {
    int64_t k = n - 1LL * p * i;
    if (k >= i) {
      k -= i;
      for (int j = 0; j < i; ++j) {
        for (int g = 60; g >= 0; --g) {
          if (k >= (1LL << g) - 1) {
            k -= (1LL << g) - 1;
            break;
          }
        }
      }
      if (k == 0) {
        cout << i << "\n";
        return 0;
      }
    }
  }
  cout << -1 << "\n";
}