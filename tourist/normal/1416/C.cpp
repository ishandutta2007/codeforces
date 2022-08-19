/**
 *    author:  tourist
 *    created: 27.09.2020 18:09:48       
**/
#undef _GLIBCXX_DEBUG

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
  vector<tuple<int, int, int>> v(n);
  long long ans = 0;
  int x = 0;
  for (int bit = 0; bit < 30; bit++) {
    for (int i = 0; i < n; i++) {
      v[i] = make_tuple(a[i] >> (bit + 1), i, (a[i] >> bit) & 1);
    }
    sort(v.begin(), v.end());
    long long inv0 = 0;
    long long inv1 = 0;
    int beg = 0;
    while (beg < n) {
      int end = beg;
      while (end + 1 < n && get<0>(v[end + 1]) == get<0>(v[end])) {
        ++end;
      }
      int k0 = 0;
      int k1 = 0;
      for (int i = beg; i <= end; i++) {
        int bit = get<2>(v[i]);
        if (bit == 0) {
          inv0 += k1;
          k0 += 1;
        } else {
          inv1 += k0;
          k1 += 1;
        }
      }
      beg = end + 1;
    }
    if (inv0 <= inv1) {
      ans += inv0;
    } else {
      ans += inv1;
      x += (1 << bit);
    }
  }
  cout << ans << " " << x << '\n';
  return 0;
}