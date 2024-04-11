/**
 *    author:  wxhtzdy
 *    created: 06.02.2022 15:55:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    if (k == 0 || s == t) {
      cout << 1 << '\n';
    } else {
      cout << 2 << '\n';
    }
  }                                                                    
  return 0;
}