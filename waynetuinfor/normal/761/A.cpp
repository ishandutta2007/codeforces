#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
  cin >> a >> b;
  if (abs(a - b) > 1) { cout << "NO\n"; return 0; }
  if (a == 0 && b == 0) { cout << "NO\n"; return 0; }
  cout << "YES\n";
  return 0;
}