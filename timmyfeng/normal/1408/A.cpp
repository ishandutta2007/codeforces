#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int a[3][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
      }
    }

    int prv = 0;
    for (int i = 0; i < n - 1; ++i) {
      int j = 0;
      while (a[j][i] == prv) {
        ++j;
      }
      cout << a[j][i] << " ";
      prv = a[j][i];
    }

    int j = 0;
    while (a[j][n - 1] == prv || a[j][n - 1] == a[0][0]) {
      ++j;
    }
    cout << a[j][n - 1] << "\n";
  }
}