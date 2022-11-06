#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c, A, B, C;

int main() {
  cin >> a >> b >> c;
  A = a / 1;
  B = b / 2;
  C = c / 4;
  cout << 7 * min({ A, B, C }) << '\n';
  return 0;
}