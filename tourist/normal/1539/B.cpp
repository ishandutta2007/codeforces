/**
 *    author:  tourist
 *    created: 20.06.2021 13:53:02       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + (int) (s[i] - 'a' + 1);
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << pref[r] - pref[l - 1] << '\n';
  }
  return 0;
}