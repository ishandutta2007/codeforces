#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  const int BLOCK = 335;
  vector<vector<int>> cnt(n, vector<int>(BLOCK));
  for (int j = 1; j < BLOCK; j++) {
    for (int i = n - 1; i >= 0; i--) {
      if (i + a[i] + j >= n) {
        cnt[i][j] = 1;
      } else {
        cnt[i][j] = cnt[i + a[i] + j][j] + 1;
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int p, k;
    cin >> p >> k;
    --p;
    if (k >= BLOCK) {
      int ans = 0;
      while (p < n) {
        ans++;
        p += a[p] + k;
      }
      cout << ans << '\n';
    } else {
      cout << cnt[p][k] << '\n';
    }
  }
}