/**
 *  author: milos
 *  created: 27.09.2020 16:10:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int bot = 0, top = *max_element(a.begin(), a.end()), ans = top;
  auto Can = [&](int x, int p) {
    int l = 0;
    for (int i = 0; i < n; i++) {
      if (l % 2 == p && a[i] <= x) {
        l++;
      } else {
        if (l % 2 != p) {
          l++;
        }
      }
    }
    if (l >= k) {
      return true;
    } else {
      return false;
    }
  };
  while (bot <= top) {
    int mid = (bot + top) / 2;
    if (Can(mid, 0) || Can(mid, 1)) {
      ans = mid;
      top = mid - 1;   
    } else {
      bot = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}