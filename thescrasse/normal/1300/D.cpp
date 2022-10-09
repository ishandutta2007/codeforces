#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, res, x[100010], y[100010], a, b, check1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  if (n % 2 == 1) {
    cout << "NO";
  } else {
    check1 = 1;
    a = x[0] + x[n / 2];
    b = y[0] + y[n / 2];
    for (i = 0; i < n / 2; i++) {
      if (x[i] + x[i + n / 2] == a && y[i] + y[i + n / 2] == b) {
      } else {
        check1 = 0;
      }
    }
    if (check1 == 1) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  }

  return 0;
}