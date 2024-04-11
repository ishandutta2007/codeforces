#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[100];
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  int my = 0;
  int coin = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (my > sum / 2) break;
    my += a[i];
    coin++;
  }
  cout << coin << endl;
  return 0;
}