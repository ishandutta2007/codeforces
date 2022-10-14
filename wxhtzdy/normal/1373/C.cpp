#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    long long ans = (int) s.length(), mn = 0, bal = 0;
    map<int, int> cnt;
    for (int i = 0; i < (int) s.length(); i++) {
      if (s[i] == '+') {
        bal++;
      } else {
        bal--;
      }
      if (bal < 0) {
        if (cnt[abs(bal)] == 0) {
          ans += i + 1;
        }
        cnt[abs(bal)] = 1;
      }
    }
    cout << ans << '\n'; 
  }
  return 0;
}