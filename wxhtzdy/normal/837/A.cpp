#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  int ans = 0, sz = 0;
  while (sz < k) {
    string s;
    cin >> s;
    int n = (int) s.length();
    sz += n + 1;
    for (int i = 0; i < n; i++) {
      int tr = 0, c = i;
      for (int j = i; j < n; j++) {
        if (s[j] == ' ') {
          break;
        }
        c = j;
        if (s[j] < 'a') {
          tr++;
        }
      }
      i = c;
      ans = max(ans, tr);
    }
  }
  cout << ans;
  return 0;
}