#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b;
  cin >> c >> d;
  cout << max(abs(a - c), abs(b - d)) << endl;
  return 0;
}