/**
 *  author: milos
 *  created: 12.01.2021 01:17:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    long long k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<long long> pos;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        pos.push_back((long long) i);
      }
    }
    for (int i = 0; i < (int) pos.size(); i++) {
      long long new_pos = max((long long) i, pos[i] - k);
      k -= pos[i] - new_pos;
      pos[i] = new_pos;
    }                 
    vector<int> ans(n, 1);
    for (int i = 0; i < (int) pos.size(); i++) {
      ans[pos[i]] = 0;
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}