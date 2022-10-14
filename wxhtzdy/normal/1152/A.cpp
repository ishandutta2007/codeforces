/**
 *  author: milos
 *  created: 07.01.2021 22:01:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> cnt(2, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x % 2] += 1; 
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    if (cnt[1 - x % 2] > 0) {
      ans += 1;
      cnt[1 - x % 2] -= 1;
    }
  }
  cout << ans << '\n';
  return 0;
}