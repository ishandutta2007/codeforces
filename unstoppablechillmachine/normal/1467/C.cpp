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
  vector<vector<int>> a(3);
  vector<int> sum(3);
  for (int i = 0; i < 3; i++) {
    int sz;
    cin >> sz;
    a[i].resize(sz);
  }
  for (int i = 0; i < 3; i++) {
    for (auto &x : a[i]) {
      cin >> x;
      sum[i] += x;
    }
    sort(all(a[i]));
  }
  int all_sum = sum[0] + sum[1] + sum[2];
  int ans = -1e18;
  for (int from = 0; from < 3; from++) {
    for (int to = 0; to < 3; to++) {
      if (from == to) {
        continue;
      }
      ans = max(ans, all_sum - 2 * sum[from]);
      ans = max(ans, all_sum - 2 * a[from][0] - 2 * a[3 - from - to][0]);
    }
  }
  cout << ans << '\n';
}