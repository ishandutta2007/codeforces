#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define st first
#define nd second
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  // n = 1500;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(n);
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      a[i][j]--;
      // a[i][j] = i * n + j;
    }
  }

  vector<int> cntR(n * n), cntC(n * n);

  for (int i = 0; i < n; i++) {
    vector<int> ind(n);
    iota(all(ind), 0);
    sort(all(ind), [&](int x, int y) {
      return a[i][x] < a[i][y];
    });
    for (int j = 0; j < n; j++)
      cntR[a[i][ind[j]]] = j;
    sort(all(ind), [&](int x, int y) {
      return a[x][i] < a[y][i];
    });
    for (int j = 0; j < n; j++)
      cntC[a[ind[j]][i]] = j;
  }
  ll ans = 0;
  for (int i = 0; i < n * n; i++) {
    ans += cntR[i] * 1ll * (n - cntC[i] - 1);
    ans += cntC[i] * 1ll * (n - cntR[i] - 1);
  }
  ans /= 2;
  cout << ans << endl;
}