#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[5];
  cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
  cout << min({a[0], a[1], a[2] / 2, a[3] / 7, a[4] / 4}) << '\n';
  return 0;
}