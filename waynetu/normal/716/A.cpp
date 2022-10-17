#include <iostream>
using namespace std;

int main() {
  int n, c;
  int t[100000];
  cin >> n >> c;
  for (int i = 0; i < n; ++i) cin >> t[i];
  int remain = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (t[i + 1] - t[i] > c) remain = 0;
    else remain++;
  }
  cout << remain + 1 << endl;
  return 0;
}