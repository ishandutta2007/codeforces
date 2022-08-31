/**
 *    author:  tourist
 *    created: 27.05.2018 17:53:17       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  map<int,int> mp;
  for (int rot = 0; rot < 2; rot++) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      mp[a] = max(mp[a], b);
    }
  }
  long long ans = 0;
  for (auto &p : mp) {
    ans += p.second;
  }
  cout << ans << '\n';
  return 0;
}