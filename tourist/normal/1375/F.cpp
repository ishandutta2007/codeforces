/**
 *    author:  tourist
 *    created: 04.07.2020 18:25:42       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b, c;
  cin >> a >> b >> c;
  cout << "First" << endl;
  auto Ask = [&](long long x) {
    cout << x << endl;
    int y;
    cin >> y;
    if (y <= 0) {
      exit(0);
    }
    if (y == 1) {
      a += x;
    }
    if (y == 2) {
      b += x;
    }
    if (y == 3) {
      c += x;
    }
  };
  Ask(a + b + c);
  vector<long long> z = {a, b, c};
  sort(z.begin(), z.end());
  long long x = z[1] - z[0];
  long long y = z[2] - z[1];
  Ask(x + 2 * y);
  z = {a, b, c};
  sort(z.begin(), z.end());
  x = z[1] - z[0];
  y = z[2] - z[1];
  assert(x == y);
  Ask(x);
  assert(false);
  return 0;
}