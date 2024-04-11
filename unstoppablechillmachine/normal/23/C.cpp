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
    vector<pair<pair<int, int>, int>> a(2 * n - 1);
    int ptr = 0;
    for (auto &it : a) {
      cin >> it.F.F >> it.F.S;
      it.S = ptr++;
    }
    sort(all(a));
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
      if (i % 2 == 0) {
        sum1 += a[i].F.S;
      }
      sum2 += a[i].F.S;
    }
    cout << "YES\n";
    if (sum1 * 2 >= sum2) {
      for (int i = 0; i < 2 * n - 1; i += 2) {
        cout << a[i].S + 1 << ' ';
      }
      cout << '\n';
    }
    else {
      for (int i  = 1; i < 2 * n - 1; i += 2) {
        cout << a[i].S + 1 << ' ';
      }
      cout << a.back().S + 1 << ' ';
      cout << '\n';
    }
  }  
}