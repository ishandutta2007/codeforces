#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }
  n /= 2;
  // int sq = int(sqrt(n));
  int cnt = n / 2;
  if (n % 2 == 0) cnt--;
  if (cnt < 0) cnt = 0;
  cout << cnt << endl;
  return 0;
}