#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << fixed << setprecision(8) << (double) (b - a) / (c + d) << "\n";
}