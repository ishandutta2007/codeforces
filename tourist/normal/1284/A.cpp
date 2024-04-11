/**
 *    author:  tourist
 *    created: 04.01.2020 15:04:29       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<string> t(m);
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int k;
    cin >> k;
    --k;
    cout << s[k % n] << t[k % m] << '\n';
  }
  return 0;
}