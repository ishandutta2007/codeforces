#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << (1 + n / 2) * (1 + n / 2) << "\n";
  } else {
    cout << (n + 1) * (n / 2 + 2) << "\n";
  }
}