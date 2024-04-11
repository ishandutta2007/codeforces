#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int q;
    long long p;
    cin >> p >> q;

    int qq = q;
    long long pp = p;
    long long factor = LLONG_MAX;
    for (int i = 2; i * i <= qq; ++i) {
      if (qq % i == 0) {
        int count_q = 0;
        while (qq % i == 0) {
          qq /= i;
          ++count_q;
        }

        int count_p = 0;
        while (pp % i == 0) {
          pp /= i;
          ++count_p;
        }

        long long diff = 1;
        for (int j = count_q - 1; j < count_p; ++j) {
          diff *= i;
        }
        factor = min(factor, diff);
      }
    }

    if (qq > 1) {
      int count_p = 0;
      while (pp % qq == 0) {
        pp /= qq;
        ++count_p;
      }

      long long diff = 1;
      for (int i = 0; i < count_p; ++i) {
        diff *= qq;
      }
      factor = min(factor, diff);
    }

    cout << p / factor << "\n";
  }
}