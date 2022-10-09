#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, res, a, b, c, d;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    cin >> a >> b >> c >> d;
    if ((b - a) % (d + c) != 0) {
      cout << -1 << endl;
    } else {
      cout << (b - a) / (d + c) << endl;
    }
  }

  return 0;
}