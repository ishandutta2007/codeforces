/**
 *    author:  wxhtzdy
 *    created: 19.07.2022 13:37:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  string s;
  cin >> s;
  int n = (int) s.size();
  set<string> st;
  for (int i = 0; i < n; i++) {
    string t = "";
    for (int j = 0; j < n; j++) {
      t += (s[(i + j) % n]);
    }
    st.insert(t);
  }
  cout << (int) st.size() << '\n';                                                      
  return 0;
}