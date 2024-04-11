/**
 *  author: milos
 *  created: 26.12.2020 12:51:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, h;
  cin >> n >> h;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto Can = [&](int x) {
    vector<int> b;
    for (int i = 0; i < x; i++) {
      b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    long long sum = 0;
    for (int i = (int) b.size() - 1; i >= 0; i -= 2) {
      sum += b[i];  
    }
    return sum <= h;
  };
  int bot = 1, top = n, ans = 1;
  while (bot <= top) {
    int mid = bot + top >> 1;
    if (Can(mid)) {
      ans = mid;
      bot = mid + 1;
    } else {
      top = mid - 1;
    }
  }
  cout << ans << '\n';
  return 0;
}