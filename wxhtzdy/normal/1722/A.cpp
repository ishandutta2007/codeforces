/**
 *    author:  wxhtzdy
 *    created: 13.10.2022 15:30:38
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
    string t = "Timur";
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    cout << (s == t ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}