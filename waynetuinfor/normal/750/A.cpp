#include <iostream>
using namespace std;

int n, k, tot;

int main() {
  cin >> n >> k;
  int t = 240 - k;
  int i;
  for (i = 0; i < n; ++i) {
    tot += (5 * i);
    if (tot + 5 * (i + 1) > t) break;
  }
  cout << i << '\n';
  return 0;
}