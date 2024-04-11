/**
 *    author:  wxhtzdy
 *    created: 22.09.2022 21:12:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  int cnt = 0;
  for (int i = 0; i + 1 < n; i++) {
    cnt += (s[i] != s[i + 1]);
  }
  int r = n - cnt;
  int l = r - 1;
  vector<pair<int, char>> ops;
  char side = (s[0] ^ 'L' ^ 'R');
  for (int i = 0; i < n; i++) {
    if (i == 0 || s[i] == s[i - 1]) {
      side = (side ^ 'L' ^ 'R');                    
      ops.emplace_back(a[order[l]], side);
      l--;
    } else {
      ops.emplace_back(a[order[r]], s[i]);
      r++;
    }
  }
  for (auto& p : ops) {
    cout << p.first << " " << p.second << '\n';
  }                                                 
  return 0;
}