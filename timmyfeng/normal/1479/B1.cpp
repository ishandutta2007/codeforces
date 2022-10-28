#include <bits/stdc++.h>
using namespace std;
 
const int N = 100000;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    for ( ; j < n && a[j] == a[i]; ++j);
    ans += 1 + (j - i > 1);
  }

  int i = 1;
  for ( ; i < n && a[i] != a[i - 1]; ++i);

  for (int j = i; i < n; i = j + 1) {
    for (j = i; j < n - 1 && a[j] != a[j + 1]; ++j);
    if (j < n - 1) {
      bool bad = (i < j && i % 2 == j % 2);
      for (int k = i; k <= j; k += 2) {
        bad &= (a[k] == a[i]);
      }
      ans -= bad;
    }
  }

  cout << ans << "\n";
}