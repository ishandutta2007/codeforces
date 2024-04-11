/**
 *    author:  tourist
 *    created: 04.11.2018 21:33:54       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  map<int,int> mp;
  vector<int> p;
  vector<int> xr;
  int n = 0;
  auto get_id = [&](int v) {
    auto it = mp.find(v);
    if (it != mp.end()) {
      return it->second;
    }
    mp[v] = n;
    p.push_back(n);
    xr.push_back(0);
    n++;
    return n - 1;
  };
  function<int(int)> find_set = [&](int x) {
    if (x != p[x]) {
      int res = find_set(p[x]);
      xr[x] ^= xr[p[x]];
      p[x] = res;
    }
    return p[x];
  };
  int ans = 0;
  while (tt--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y, z;
      cin >> x >> y >> z;
      x ^= ans;
      y ^= ans;
      z ^= ans;
      if (x > y) swap(x, y);
//      cerr << "query 1 " << x << " " << y << " " << z << '\n';
      y++;
      x = get_id(x);
      y = get_id(y);
      int xx = find_set(x);
      int yy = find_set(y);
      if (xx != yy) {
        p[xx] = yy;
        xr[xx] = xr[x] ^ xr[y] ^ z;
      }
    } else {
      int x, y;
      cin >> x >> y;
      x ^= ans;
      y ^= ans;
      if (x > y) swap(x, y);
//      cerr << "query 2 " << x << " " << y << '\n';
      y++;
      x = get_id(x);
      y = get_id(y);
      int xx = find_set(x);
      int yy = find_set(y);
      if (xx == yy) {
        ans = xr[x] ^ xr[y];
      } else {
        ans = -1;
      }
      cout << ans << '\n';
      ans = abs(ans);
    }
  }
  return 0;
}