/**
 *    author:  wxhtzdy
 *    created: 11.02.2022 12:33:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = accumulate(a.begin(), a.end(), 0LL);
  int q;
  cin >> q;
  vector<int> b(n);
  map<pair<int, int>, int> mp; 
  function<void(int)> Rem = [&](int x) {
    if (x == -1) {
      return;
    }           
    ans -= max(0, a[x] - b[x]);
    b[x] -= 1;
    ans += max(0, a[x] - b[x]);
  };
  function<void(int)> Add = [&](int x) {
    if (x == -1) {
      return;
    }           
    ans -= max(0, a[x] - b[x]);
    b[x] += 1;
    ans += max(0, a[x] - b[x]);
  };
  while (q--) {
    int s, t, u;
    cin >> s >> t >> u;
    --s; --u;
    if (mp.count({s, t})) {
      Rem(mp[{s, t}]);
    }
    mp[{s, t}] = u;
    Add(u);
    cout << ans << '\n';
  }                                                     
  return 0;
}