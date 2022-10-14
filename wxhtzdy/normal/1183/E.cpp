/**
 *    author:  milos
 *    created: 28.01.2021 10:17:58       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<string> que(1, s);
  set<string> all;
  all.insert(s);
  int ans = 0;
  for (int b = 0; b < (int) que.size(); b++) {
    string x = que[b];
    for (int j = 0; j < (int) que[b].size(); j++) {
      string new_s = x;
      new_s.erase(j, 1);
      if ((int) all.size() < k && all.find(new_s) == all.end()) {
        que.push_back(new_s);
        ans += n - (int) new_s.size();
        all.insert(new_s);
      }
    }
  }
  if ((int) all.size() < k) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
  return 0;
}