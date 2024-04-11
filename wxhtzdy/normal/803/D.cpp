/**
 *    author: m371
 *    created: 17.10.2021 10:14:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  string s;
  getline(cin, s);
  getline(cin, s);
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '-') {
      s[i] = ' ';
    }
  }
  auto Can = [&](int x) {
    int curr = 0, total = 0;
    while (curr < n) {
      int nxt = -1;
      for (int i = 0; i < x; i++) {
        if (curr + i >= n - 1 || s[curr + i] == ' ') {
          nxt = curr + i;
        }
      }
      if (nxt == -1) {
        return false;
      }
      total += 1;
      curr = nxt + 1;
    }
    return total <= k;
  };
  int low = 1, high = n, ans = n;
  while (low <= high) {
    int mid = low + high >> 1;
    if (Can(mid)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << ans << '\n';  
  return 0;
}