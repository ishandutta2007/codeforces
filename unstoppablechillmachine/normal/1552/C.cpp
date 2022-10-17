#pragma GCC optimize("Ofast")
#pragma GCC optiize("unroll-loops")
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
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    vector<bool> used(2 * n);
    for (int i = 0; i < m; i++) {
      cin >> l[i] >> r[i];
      l[i]--;
      r[i]--;
      used[l[i]] = true;
      used[r[i]] = true;
    }
    vector<int> have;
    for (int i = 0; i < 2 * n; i++) {
      if (!used[i]) {
        have.pb(i);
      }
    }
    auto inter = [](int a, int b, int c, int d) {
      if (a > b) {
        swap(a, b);
      }
      if (c > d) {
        swap(c, d);
      }
      if (a >= c && b <= d) {
        return 0;
      }
      if (c >= a && d <= b) {
        return 0;
      }
      if (c > b || a > d) {
        return 0;
      }
      return 1;
    };
    assert(SZ(have) == 2 * (n - m));
    int answer = 0;
    for (int i = 0; i < n - m; i++) {
      for (int j = 0; j < m; j++) {
        answer += inter(have[i], have[i + n - m], l[j], r[j]);
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = i + 1; j < m; j++) {
        answer += inter(l[i], r[i], l[j], r[j]);
      }
    }
    cout << answer + (n - m) * (n - m - 1) / 2 << '\n'; 
  }
}