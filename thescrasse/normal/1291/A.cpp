#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, c, res;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    c = 0;
    res = 0;
    cin >> n >> s;
    for (i = 0; i < n; i++) {
      if (s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9') {
        c++;
        if (c <= 2) {
          res = 10 * res + s[i] - 48;
        }
      }
    }
    if (c >= 2) {
      cout << res << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}