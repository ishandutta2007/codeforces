#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int gcd = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    gcd = __gcd(gcd, a[i]);
  }

  for (int i = 0; i < n; ++i) {
    a[i] /= gcd;
    for (auto j : {2, 3}) {
      while (a[i] % j == 0) {
        a[i] /= j;
      }
    }
    if (a[i] > 1) {
      cout << "No\n";
      exit(0);
    }
  }

  cout << "Yes\n";
}