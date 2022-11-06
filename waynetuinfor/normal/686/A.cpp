#include <iostream>
#define int long long
using namespace std;

int n, x, d, cnt;
char c;

signed main() {
  cin >> n >> x;
  while (n--) {
    cin >> c >> d;
    if (c == '+') x += d;
    else {
      if (x >= d) x -= d;
      else cnt++;
    }
  }
  cout << x << ' ' << cnt << '\n';
  return 0;
}