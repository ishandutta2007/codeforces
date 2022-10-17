#pragma GCC optimize("no-stack-protector")
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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &it : a) {
      cin >> it;
    }
    for (auto &it : b) {
      cin >> it;
    }
    vector<pair<int, int>> have1, have2;
    for (int i = 0; i < n / 2; i++) {
      have1.pb({min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1])});
    }
    for (int i = 0; i < n / 2; i++) {
      have2.pb({min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1])});
    }
    sort(all(have1));sort(all(have2));
    bool ok = (have1 == have2);
    if (n & 1) {
      ok &= (a[n / 2] == b[n / 2]);
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}