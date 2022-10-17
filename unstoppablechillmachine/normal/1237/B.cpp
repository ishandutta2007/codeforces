#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = 1e5 + 10;
int a[N], pos[N];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pos[x] = i;
  }
  int mx = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (mx > pos[a[i]]) {
      ans++;
    }
    mx = max(mx, pos[a[i]]);
  }
  cout << ans << '\n';
}