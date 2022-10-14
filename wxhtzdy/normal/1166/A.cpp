/**
 *  author: milos
 *  created: 10.01.2021 00:35:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> cnt(26, 0);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    cnt[(int) (s[0] - 'a')] += 1;
  }
  long long ans = 0;
  for (int i = 0; i < 26; i++) {
    long long x = cnt[i] / 2, y = (cnt[i] + 1) / 2;
    ans += x * (x - 1) / 2;
    ans += y * (y - 1) / 2;
  }
  cout << ans << '\n';
  return 0;
}