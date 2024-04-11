#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<string, int> cnt;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    cnt[s] += 1;
  }
  pair<string, int> ans;
  ans.first = "";
  ans.second = 0;
  for (auto c : cnt) {
    if (c.second >= ans.second) {
      ans.second = c.second;
      ans.first = c.first;
    }
  }
  cout << ans.first << '\n';
  return 0;
}