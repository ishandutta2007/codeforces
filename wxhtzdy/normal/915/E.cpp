#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  map<int, int> mp;
  mp[1] = n;
  int len = n;
  function<void(int)> Cut = [&](int i) {
    if (!mp.count(i)) {
      auto it = mp.lower_bound(i);
      if (it != mp.begin()) {
        it = prev(it);
        if (it->second < i) {
          return;
        }
        int r = it->second;
        mp[it->first] = i - 1;
        mp[i] = r;
      }
    }
  };
  function<void(int, int)> Rem = [&](int l, int r) {
    auto it = mp.lower_bound(l);
    while (it != mp.end() && it->first <= r) {
      len -= (it->second - it->first + 1);
      it = mp.erase(it);
    }
  };
  while (q--) {
    int l, r, foo;
    cin >> l >> r >> foo;
    Cut(l);
    Cut(r + 1);
    Rem(l, r);
    if (foo == 2) {
      len += (r - l + 1);
      mp[l] = r;
    }
    cout << len << '\n';
  }
  return 0;
}