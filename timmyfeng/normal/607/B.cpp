#include <bits/stdc++.h>
using namespace std;

const int N = 500;

int mini[N][N], a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 0; i + k - 1 < n; ++i) {
      int j = i + k - 1;
      if (k == 1) {
        mini[i][j] = 1;
      } else if (k == 2) {
        mini[i][j] = (a[i] == a[j]) ? 1 : 2;
      } else {
        mini[i][j] = k;
        for (int l = i; l < j; ++l) {
          mini[i][j] = min(mini[i][j], mini[i][l] + mini[l + 1][j]); 
        }

        if (a[i] == a[j]) {
          mini[i][j] = min(mini[i][j], mini[i + 1][j - 1]);
        }
      }
    }
  }

  cout << mini[0][n - 1] << "\n";
}