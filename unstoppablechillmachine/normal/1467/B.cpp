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
 
int f(vector<int> &a, int id) {
  
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    auto f = [&](int id) {
      if (id <= 1 || id >= SZ(a) - 1) {
        return 0;
      }
      if (a[id] < a[id - 1] && a[id] < a[id + 1]) {
        return 1;
      }
      if (a[id] > a[id - 1] && a[id] > a[id + 1]) {
        return 1;
      }
      return 0;
    };
    int sum = 0;
    for (int i = 2; i < n; i++) {
      sum += f(i);
    }
    int ans = sum;
    auto update = [&](int pos, int to) {
      int cur = sum;
      cur -= f(pos - 1);
      cur -= f(pos);
      cur -= f(pos + 1);
      int was = a[pos];
      a[pos] = to;
      cur += f(pos - 1);
      cur += f(pos);
      cur += f(pos + 1);
      ans = min(ans, cur);
      a[pos] = was;
    };
    for (int pos = 1; pos <= n; pos++) {
      if (pos > 1) {
        for (int to = a[pos - 1] - 1; to <= a[pos - 1] + 1; to++) {
          update(pos, to);  
        }
      }
      if (pos < n) {
        for (int to = a[pos + 1] - 1; to <= a[pos + 1] + 1; to++) {
          update(pos, to);
        }
      }
    }
    cout << ans << '\n';
  }
}