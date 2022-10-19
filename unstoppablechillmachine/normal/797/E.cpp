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

const int N = 2e5 + 10;
const int B = 200;
int a[N], op[N][B];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= B; j++) {
      int to = i + a[i] + j;
      if (to > n) {
        op[i][j] = 1;
      }
      else {
        op[i][j] = 1 + op[to][j];
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int p, k;
    cin >> p >> k;
    if (k <= B) {
      cout << op[p][k] << '\n';
    }
    else {
      int pos = p, ans = 0;
      while (pos <= n) {
        pos = pos + a[pos] + k;
        ans++;
      }
      cout << ans << '\n';
    }
  }
}