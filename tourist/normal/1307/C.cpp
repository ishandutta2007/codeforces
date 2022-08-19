/**
 *    author:  tourist
 *    created: 17.02.2020 18:38:57       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  const int ALPHA = 26;
  int n = (int) s.size();
  vector<vector<int>> all(ALPHA);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = (int) (s[i] - 'a');
    all[(int) (s[i] - 'a')].push_back(i);
  }
  long long ans = 0;
  for (int i = 0; i < ALPHA; i++) {
    ans = max(ans, (long long) all[i].size());
  }
  for (int i = 0; i < ALPHA; i++) {
    for (int j = 0; j < ALPHA; j++) {
      long long cur = 0;
      int cc = 0;
      for (int k = 0; k < n; k++) {
        if (a[k] == j) {
          cur += cc;
        }
        if (a[k] == i) {
          cc += 1;
        }
      }
      ans = max(ans, cur);
    }
  }
  cout << ans << '\n';
  return 0;
}