/**
 *    author:  wxhtzdy
 *    created: 05.09.2022 17:46:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, d;
  cin >> n >> d;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  int ptr = 0;
  int ans = 0;
  for (int i = n - 1; i >= ptr; i--) {
    int nxt = ptr + d / p[i];
    if (nxt <= i) {
      ptr = nxt;
      ans += 1;            
    }
  }
  cout << ans << '\n';                                                    
  return 0;
}