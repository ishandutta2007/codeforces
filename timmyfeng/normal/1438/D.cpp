#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    sum ^= a;
  }

  if (n % 2 == 0) {
    if (sum != 0) {
      cout << "NO\n";
      exit(0);
    }
    --n;
  }

  cout << "YES\n";
  cout << n - 1 << "\n";
  for (int i = 0; i < n - 1; i += 2) {
    for (int j = 0; j < 3; ++j) {
      cout << i + j + 1 << " ";
    }
    cout << "\n";
  }
  for (int i = n - 3; i >= 0; i -= 2) {
    for (int j = 0; j < 3; ++j) {
      cout << i + j + 1 << " ";
    }
    cout << "\n";
  }
}