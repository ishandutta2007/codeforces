#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    if (n % i == 0 && n / i < k) {
      cout << i * k + n / i << "\n"; 
      exit(0);
    }
  }
  assert(0);
}