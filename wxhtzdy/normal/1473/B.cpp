/**
 *  author: milos
 *  created: 14.01.2021 15:39:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    if ((int) s.size() < (int) t.size()) swap(s, t);
    string ans = "";
    auto Ok = [&](string mudja) {
      int aa = 0, bb = 0;
      if ((int) mudja.size() % (int) s.size() != 0) return false;
      if ((int) mudja.size() % (int) t.size() != 0) return false;
      //cout << mudja << '\n';
      string xx = "", yy = "";
      for (int i = 0; i < (int) mudja.length(); i++) {
        if (mudja[i] != s[aa]) return false;
        if (mudja[i] != t[bb]) return false;
        aa++;
        bb++;
        aa %= (int) s.size();
        bb %= (int) t.size();
      }
      return true;
    };
    bool ok = false;
    for (int i = 0; i < (int) 200; i++) {
      ans += s;
      if (Ok(ans) == true) {
        cout << ans << '\n';
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
    }
  }
  return 0;
}