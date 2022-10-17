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

inline int f(int a, int from_x) {
  return a - 3ll * from_x * from_x - 3ll * from_x - 1;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int min_delta = 9e18, max_delta = -9e18;
  for (int &x : a) {
    cin >> x;
    min_delta = min(min_delta, f(x, x - 1));
    max_delta = max(max_delta, f(x, 0ll));
  }  
  int l = min_delta, r = max_delta + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2, sum = 0;
    for (int i = 0; i < n; i++) {
      int lo = 0, hi = a[i] + 1;
      while (hi - lo > 1) {
        int cmid = (lo + hi) / 2;
        if (f(a[i], cmid - 1) >= mid) {
          lo = cmid;
        }
        else {
          hi = cmid;
        }
      }
      sum += lo;
    }
    //cout << mid << ' ' << sum << '\n';
    if (sum >= k) {
      l = mid;
    }
    else {
      r = mid;
    }
  }
  vector<int> ans(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int lo = 0, hi = a[i] + 1;
    while (hi - lo > 1) {
      int mid = (lo + hi) / 2;
      if (f(a[i], mid - 1) >= l) {
        lo = mid;
      }
      else {
        hi = mid;
      }
    }
    ans[i] = lo;
    cnt += ans[i];
  }
  for (int i = 0; i < n; i++) {
    while (ans[i] > 0 && f(a[i], ans[i] - 1) == l && cnt > k) {
      ans[i]--;
      cnt--;
    }
    cout << ans[i] << ' ';
  }
  cout << '\n';
}