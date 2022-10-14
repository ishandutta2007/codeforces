/**
 *  author: milos
 *  created: 14.12.2020 11:54:16
**/
#include <bits/stdc++.h>

using namespace std;
          
const int N = 1e6 + 5;

vector<vector<int>> in(N), out(N);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    in[l[i]].push_back(i);
    out[r[i] + 1].push_back(i);
  }
  vector<int> ans;
  multiset<pair<int, int>> s;
  for (int i = 1; i < N; i++) {
    for (int c : in[i]) {
      s.insert({r[c], c});
    }
    for (int c : out[i]) {
      s.erase({r[c], c});  
    }
    while ((int) s.size() > k) {
      auto it = s.end();
      --it;
      ans.push_back((*it).second);
      s.erase(it);  
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}