#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  if (a > b) swap(a, b);
  for (int i = a; i >= 1; i--) {
    if (a / i + b / i >= n) {
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}