#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> sum1(n + 1), sum2(m + 1);
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      sum1[i] += a[i][j];
      sum2[j] += a[i][j];
    }
  }
  vector<int> flip1(n + 1, 0), flip2(m + 1, 0);
  for (;;) {
    bool fnd = false;
    for (int i = 1; i <= n; i++) {
      if (sum1[i] < 0) {
        sum1[i] *= -1;
        flip1[i] ^= 1;
        fnd = true;
        for (int j = 1; j <= m; j++) {
          a[i][j] *= -1;
          sum2[j] += 2 * a[i][j];
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      if (sum2[i] < 0) {
        sum2[i] *= -1;
        flip2[i] ^= 1;
        fnd = true;
        for (int j = 1; j <= n; j++) {
          a[j][i] *= -1;
          sum1[j] += 2 * a[j][i];
        }
      }
    }
    if (!fnd) {
      break;
    }
  }
  vector<int> rez1, rez2;
  for (int i = 1; i <= n; i++) {
    if (flip1[i]) {
      rez1.pb(i);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (flip2[i]) {
      rez2.pb(i);
    }
  }
  cout << SZ(rez1) << ' ';
  for (int &x : rez1) {
    cout << x << ' ';
  }
  cout << '\n';
  cout << SZ(rez2) << ' ';
  for (int &x : rez2) {
    cout << x << ' ';
  }
  cout << '\n';
}