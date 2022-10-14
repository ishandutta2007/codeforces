/**
 *    author:  wxhtzdy
 *    created: 01.02.2022 09:17:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    vector<int> cnt(2);
    for (int i = 0; i < s.size(); i++) {
      cnt[s[i] - '0'] += 1;
    }
    cout << min(cnt[0], cnt[1]) - (cnt[0] == cnt[1]) << '\n';
  }                                                                    
  return 0;
}