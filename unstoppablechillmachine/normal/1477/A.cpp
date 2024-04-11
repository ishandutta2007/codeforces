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
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (auto &it : x) {
      cin >> it;
    }
    sort(all(x));
    int d = x[1] - x[0];
    auto gcd = [&](int a, int b) {
      while (b) {
        a %= b;
        swap(a, b);
      }
      return a;
    };
    for (int i = 2; i < n; i++) {
      d = gcd(d, x[i] - x[i - 1]);
    }
    auto abs = [&](int x) {
      return (x < 0 ? -x : x);
    };
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (x[i] == k || abs(x[i] - k) % d == 0) {
        ok = true;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}