#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y, z, a, b, c;
  cin >> x >> y >> z >> a >> b >> c;
  cout << (abs(z - x) * b + abs(y - x) * b + 3 * c <= abs(y - x) * a ? "YES" : "NO") << "\n";
}