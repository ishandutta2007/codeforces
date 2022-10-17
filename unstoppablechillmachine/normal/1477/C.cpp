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
  int n;
  cin >> n;
  vector<int> x(n + 1), y(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  vector<int> ans = {1};
  vector<bool> used(n + 1);
  used[1] = true;
  auto d = [&](int a, int b) {
    return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
  };
  for (int i = 0; i < n - 1; i++) {
    pair<int, int> best = {0, -1};
    for (int j = 1; j <= n; j++) {
      if (!used[j]) {
        best = max(best, make_pair(d(ans.back(), j), j));
      } 
    }
    used[best.S] = true;
    ans.pb(best.S);
  }
  for (auto it : ans) {
    cout << it << ' ';
  }
  cout << '\n';
}