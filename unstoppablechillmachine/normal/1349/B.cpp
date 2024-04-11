#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 1e5 + 10;
int a[N], pref[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    bool have = false;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (x == k) {
        have = true;
      }
      if (x >= k) {
        a[i] = 1;
        cnt++;
      }
      else {
        a[i] = -1;
      }
    }
    if (!have) {
      cout << "no\n";
      continue;
    }
    bool ok = false;
    if (cnt == n) {
      ok = true;
    }
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + a[i];
    }
    int min_pref = 0;
    for (int i = 2; i <= n; i++) {
      if (pref[i] - min_pref > 0) {
        ok = true;
      }
      min_pref = min(min_pref, pref[i - 1]);
    }
    cout << (ok ? "yes" : "no") << '\n';
  }
}