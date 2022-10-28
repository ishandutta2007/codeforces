#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c = 0;
  cin >> a >> b;

  while (min(a, b) > 0 && max(a, b) > 1) {
    if (a > b) {
      swap(a, b);
    }
    ++a, b -= 2, ++c;
  }

  cout << c << "\n";
}