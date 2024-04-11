#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int y, b, r;
  cin >> y >> b >> r;

  y -= 1;
  b -= 2;
  r -= 3;

  cout << 6 + min({y, b, r}) * 3 << "\n";
}