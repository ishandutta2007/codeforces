#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> pos(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
    pos[a[i]].push_back(i);
  }
  int R = 0, ans = 0, where = 0;              
  for (int i = 0; i < n; i++) {
    R = max(R, pos[a[i]].back());
    if (i < where) {
      ans += 1;
    } else {
      where = R;  
    }
  }
  cout << ans << '\n';
  return 0;
}