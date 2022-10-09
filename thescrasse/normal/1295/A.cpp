#include <bits/stdc++.h>
using namespace std;

long long i, j, k, t, n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  for (j = 0; j < t; j++) {
    cin >> n;
    if (n % 2 == 0) {
      for (i = 0; i < n; i = i + 2) {
        cout << "1";
      }
    } else {
      cout << "7";
      for (i = 3; i < n; i = i + 2) {
        cout << "1";
      }
    }
    cout << endl;
  }
  return 0;
}