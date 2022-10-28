#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int a[2][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      cin >> a[j][i];
    }
  }

  for (int i = 0; i < 2; ++i) {
    sort(a[i], a[i] + n);
  }

  long long ans = n;
  for (int i = 0; i < n; ++i) {
    ans += max(a[0][i], a[1][i]);
  }

  cout << ans << "\n";
}