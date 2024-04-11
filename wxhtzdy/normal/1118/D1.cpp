/**
 *  author: milos
 *  created: 04.01.2021 12:17:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sum = accumulate(a.begin(), a.end(), 0);
  if (sum < m) {
    cout << -1 << '\n';
    return 0;
  }
  sort(a.rbegin(), a.rend());
  auto Can = [&](int d) {
    if (d == 0) {
      return false;
    }
    int cnt = 0, j = 0;
    long long x = 0;
    for (int i = 0; i < n; i++) {
      x += max(0, a[i] - i / d); 
    }
    return x >= m;
  };
  int bot = 0, top = n, ans = 1;
  while (bot <= top) {
    int mid = bot + top >> 1;
    if (Can(mid)) {
      ans = mid;
      top = mid - 1;
    } else {
      bot = mid + 1;
    }
  }  
  if (Can(ans - 1)) ans -= 1;
  cout << ans << '\n';  
  return 0;
}