#include <iostream>
using namespace std;

bool even(int x) {
  return x % 2 == 0 ? true : false;
}

int main() {
  int w;
  cin >> w;
  for (int i = 1; i < w; ++i) {
    if (even(i) && even(w - i)) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}