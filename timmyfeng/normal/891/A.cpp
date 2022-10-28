#include <bits/stdc++.h>
using namespace std;

const int N = 2000;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (count(a, a + n, 1) > 0) {
    cout << n - count(a, a + n, 1) << "\n";
    exit(0);
  }

  int mn = n + 1;
  for (int i = 0; i < n; ++i) {
    int g = 0;
    for (int j = i; j < n; ++j) {
      g = gcd(g, a[j]);
      if (g == 1) {
        mn = min(mn, j - i);
        break;
      }
    }
  }

  cout << (mn == n + 1 ? -1 : n - 1 + mn) << "\n";
}