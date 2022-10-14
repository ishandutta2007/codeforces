/**
 *  author: milos
 *  created: 07.01.2021 22:08:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int cnt = 0;
  auto Ok = [&](int x) {
    for (int i = 20; i >= 0; i--) {
      if (x == ((int) (1 << i) - 1)) {
        return true;
      }
    }
    return false;
  };
  auto Find = [&](int x) {
    for (int i = 20; i >= 0; i--) {
      if ((x & (1 << i)) != 0) {
        return i;
      }
    }
    return 0;
  };
  vector<int> ans;
  while (!Ok(n)) {
    if (cnt % 2 == 0) {  
      int pos = Find(n);
      if ((1 << pos) != n) {
        pos += 1;
      }
      n ^= (1 << pos) - 1;
      ans.push_back(pos);
    } else {
      n += 1;
    }
    cnt += 1;
  }
  cout << cnt << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}