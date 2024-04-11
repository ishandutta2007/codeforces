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
  set<pair<int, int>> ans;
  for (int i = 1; i <= n; i++) {
    ans.insert({i, n - i + 1});
  }
  vector<int> a(n + 1);
  vector<int> one, not0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (!a[i]) {
      ans.erase({n - i + 1, i});
    }
    if (a[i]) {
      not0.pb(i);
    }
    if (a[i] == 1) {
      one.pb(i);
    }
  }
  reverse(all(not0));
  reverse(all(one));
  vector<bool> used(n + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] == 2) {
      while (!one.empty() && one.back() < i) {
        one.pop_back();
      }
      if (one.empty()) {
        cout << -1 << '\n';
        exit(0);
      }
      ans.erase({n - i + 1, i});
      ans.insert({n - one.back() + 1, i});
      used[one.back()] = true;
      one.pop_back();
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 3) {
      while (!not0.empty() && (not0.back() <= i || used[not0.back()])) {
        not0.pop_back();
      }
      if (not0.empty()) {
        cout << -1 << '\n';
        exit(0);
      }
      ans.insert({n - i + 1, not0.back()});
      not0.pop_back();
    }
  }
  cout << SZ(ans) << '\n';
  for (auto it : ans) {
    cout << n - it.F + 1 << ' ' << it.S << '\n';
  }
}