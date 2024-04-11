#include <bits/stdc++.h>
using namespace std;

const int N = 5001;

int ans[N][N];
int a[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i][1];
    ans[i][1] = a[i][1];
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j + i <= n; ++j) {
      a[j][i + 1] = a[j][i] ^ a[j + 1][i];
      ans[j][i + 1] = max({a[j][i + 1], ans[j][i], ans[j + 1][i]});
    }
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    cout << ans[l][r - l + 1] << "\n";
  }
}