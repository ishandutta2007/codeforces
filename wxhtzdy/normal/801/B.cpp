#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  string s, t;
  cin >> s >> t;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] < t[i]) {
      cout << -1 << '\n';
      return 0;
    }
  }
  cout << t << '\n';                                                        
  return 0;
}