#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, res, a[110], m, b, check1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    check1 = 0;
    for (i = 0; i < n; i++) {
      if (a[i] % 2 == 0 && check1 == 0) {
        cout << 1 << endl << i + 1 << endl;
        check1 = 1;
      }
    }
    if (check1 == 0 && n == 1) {
      cout << -1 << endl;
    } else if (check1 == 0) {
      cout << 2 << endl << "1 2" << endl;
    }
  }

  return 0;
}