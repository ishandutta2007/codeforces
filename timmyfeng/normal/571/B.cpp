#include <bits/stdc++.h>
using namespace std;
 
const int N = 300000 + 1;
const int K = 5000;
 
int mini[K][K], a[N];
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n, k;
  cin >> n >> k;
  int l = n / k, r = n % k;
 
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);

  for (int i = 0; i <= r; ++i) {
    for (int j = 0; j <= k - r; ++j) {
      int prefix = i * (l + 1) + j * l;
      mini[i][j] = (i == 0 && j == 0) ? 0 : INT_MAX;
      if (i > 0) {
        mini[i][j] = min(mini[i][j], mini[i - 1][j] + a[prefix - 1] - a[prefix - l - 1]);
      }
      if (j > 0) {
        mini[i][j] = min(mini[i][j], mini[i][j - 1] + a[prefix - 1] - a[prefix - l]);
      }
    }
  }

  cout << mini[r][k - r] << "\n";
}