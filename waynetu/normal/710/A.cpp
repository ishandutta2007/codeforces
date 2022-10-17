#include <iostream>
using namespace std;

int main() {
  char c1, c2;
  cin >> c1 >> c2;
  int n = 8;
  if (c1 == 'a' || c1 == 'h') {
    n = n / 2 + 1;
  }
  if (c2 == '1' || c2 == '8') {
    n = n / 2 + 1;
  }
  cout << n << endl;
  return 0;
}