#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, c, res, a[300010], k1, k2;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    k1 = n;
    k2 = -1;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i = 0; i < n; i++) {
      if (a[i] < i) {
        k1 = i - 1;
        break;
      }
    }
    for (i = 0; i < n; i++) {
      if (a[n - i - 1] < i) {
        k2 = n - i;
        break;
      }
    }
    if (k2 > k1) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }

  return 0;
}