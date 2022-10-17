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
    int n, L;
    cin >> n >> L;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    int l = -1, r = n;
    ld ctime = 0, co1 = 0, co2 = L;
    ld v1 = 1, v2 = 1;
    while (r - l > 1) {
      if ((a[l + 1] - co1) * 1.0 / v1 < (co2 - a[r - 1]) * 1.0 / v2) {
        ctime += (a[l + 1] - co1) * 1.0 / v1;
        co2 -= v2 * ((a[l + 1] - co1) * 1.0 / v1);
        v1++;
        co1 = a[l + 1];
        l++;
      }
      else {
        ctime += (co2 - a[r - 1]) * 1.0 / v2;
        co1 += v1 * ((co2 - a[r - 1]) * 1.0 / v2);
        v2++;
        co2 = a[r - 1];
        r--;
      }
    }
    ctime += (co2 - co1) * 1.0 / (v1 + v2);
    cout << fixed << setprecision(10) << ctime << '\n';
  }   
}