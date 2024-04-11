#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int mx = max(max(a, b), c);
  int mn = min(min(a, b), c);
  cout << mx - mn << endl;
  return 0;
}