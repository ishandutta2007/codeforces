/**
 *    author:  wxhtzdy
 *    created: 07.06.2022 21:31:02
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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      --p[i];
    }               
    vector<bool> was(n, false);
    long long ans = 1;
    auto Rotate = [&](string str) {
      string ret = "";
      ret += str.back();
      for (int i = 0; i + 1 < str.size(); i++) {
        ret += str[i];
      }
      return ret;
    };
    for (int i = 0; i < n; i++) {
      if (was[i]) {
        continue;
      }
      int x = i;
      vector<int> ids;
      while (!was[x]) {
        was[x] = true;
        ids.push_back(x);
        x = p[x];
      }
      string t = "";
      for (int j : ids) {
        t += s[j];
      }
      string str = Rotate(t);
      long long cc = 1;
      while (str != t) {
        str = Rotate(str);
        cc += 1;
      }
      ans = (ans * cc) / __gcd(ans, cc); 
    }
    cout << ans << '\n';
  }                                                                      
  return 0;
}