#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;

signed main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int sum = 0;
  vector<int> a(n);
  for (auto &it : a) {
    cin >> it;
    sum += it;
  }
  int csum = a[0];
  vector<int> ans = {0};
  for (int i = 1; i < n; i++) {
    if (a[i] * 2 <= a[0]) {
      ans.pb(i);
      csum += a[i];
    }
  }
  if (csum * 2 > sum) {
    cout << SZ(ans) << '\n';
    for (auto it : ans) {
      cout << it + 1 << ' ';
    }
    cout << '\n';
  }
  else {
    cout << 0 << '\n';
  }
}