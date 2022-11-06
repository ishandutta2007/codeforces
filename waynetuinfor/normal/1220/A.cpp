#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> cnt(256);
  for (int i = 0; i < n; ++i) cnt[s[i]]++;
  int ans = min(cnt['o'], cnt['e']);
  int x = min(cnt['z'], cnt['r']);
  int y = cnt['n'];
  int r = min(ans, y);
  for (int i = 0; i < r; ++i) cout << "1 ";
  ans -= r;
  for (int i = 0; i < min(ans, x); ++i) cout << "0 ";
  cout << endl;
}