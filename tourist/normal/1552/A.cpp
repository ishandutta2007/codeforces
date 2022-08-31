/**
 *    author:  tourist
 *    created: 25.07.2021 17:35:00       
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
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    int k = 0;
    for (int i = 0; i < (int) s.size(); i++) {
      k += (s[i] != t[i]);
    }
    cout << k << '\n';
  }
  return 0;
}