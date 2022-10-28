#include <bits/stdc++.h>
using namespace std;

const int N = 500000;

int a[N], b[N];
bool diff[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i < n - 1; ++i) {
    diff[i] = (a[i - 1] != a[i] && a[i] != a[i + 1]);
  }

  int ans = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    if (!diff[i]) {
      b[i] = a[i];
      j = i + 1;
    } else {
      for ( ; diff[j]; ++j);
      ans = max(ans, (j - i + 1) / 2);
      for (int k = i; k < j; ++k) {
        if (k - i < j - k) {
          b[k] = a[i - 1];
        } else {
          b[k] = a[j];
        }
      }
    }
  }

  cout << ans << "\n";
  for (int i = 0; i < n; ++i) {
    cout << b[i] << " ";
  }
  cout << "\n";
}