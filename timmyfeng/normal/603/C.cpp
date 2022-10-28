#include <bits/stdc++.h>
using namespace std;

int grundy(int n, int k) {
  if (k % 2 == 0) {
    return (n < 3) ? n : 1 - n % 2;
  } else {
    if (n <= 3) {
      return n % 2;
    } else if (n % 2 == 1) {
      return 0;
    } else {
      int g = grundy(n - 1, k) ^ grundy(n / 2, k);
      return (g == 0) ? 1 : 3 - g;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ans ^= grundy(a, k);
  }

  cout << (ans == 0 ? "Nicky" : "Kevin") << "\n";
}