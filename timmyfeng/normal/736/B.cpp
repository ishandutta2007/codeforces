#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (prime(n)) {
    cout << 1 << "\n";
  } else if (n % 2 == 0) {
    cout << 2 << "\n";
  } else if (prime(n - 2)) {
    cout << 2 << "\n";
  } else {
    cout << 3 << "\n";
  }
}