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
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        pos.push_back(i);
      }
    }
    int ans = 0;
    for (int id = 0; id + 1 < pos.size(); id++) {
      int i = pos[id];
      if (s[i + 1] == '0') {
        ans += 2;
      } else if (s[i + 2] == '0') {
        ans += 1;
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}