#include <bits/stdc++.h>
using namespace std;
int main() {
  int tux;
  cin >> tux;
  int foo = 0, bar = 0, baz = 0, quz = 1;
  for (int i = 1; i <= tux; i++) {
    int pur;
    cin >> pur;
    foo += pur;
    ++bar;
    if (foo * quz > baz * bar) {
      baz = foo;
      quz = bar;
    }
  }
  cout << (double)baz / quz << endl;
  return 0;
}