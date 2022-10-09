#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, check1, a, b, diff, diff2;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> a >> b;
  if (a > b || (b - a) % 2 == 1) {
      cout << -1;
      return 0;
  }
  if (a == 0 && b == 0) {
      cout << 0;
      return 0;
  }
  if (a == b) {
      cout << 1 << endl << a;
      return 0;
  }

  diff = b - a;
  diff2 = diff / 2;
  if ((diff2 | a) == diff2 + a) {
      cout << 2 << endl << diff2 + a << ' ' << diff2;
      return 0;
  }
  cout << 3 << endl << diff2 << ' ' << diff2 << ' ' << a;

  return 0;
}