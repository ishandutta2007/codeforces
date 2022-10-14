/**
 *    author:  wxhtzdy
 *    created: 13.07.2022 15:18:08
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
    set<char> st;
    for (int i = 0; i < (int) s.size(); i++) {
      st.insert(s[i]);
    }
    cout << (int) s.size() + (int) st.size() << '\n';
  }                                                                    
  return 0;
}