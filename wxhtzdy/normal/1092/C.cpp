/**
 *    author:  milos
 *    created: 23.01.2021 20:43:26       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(2 * n - 2);
  vector<string> t;
  for (int i = 0; i < 2 * n - 2; i++) {
    cin >> s[i];
    if ((int) s[i].size() == n - 1) {
      t.push_back(s[i]);
    }
  }
  string ans = "";
  auto Solve = [&](string pref, string suff) {
    string k = pref + suff[n - 2];
    ans = "";
    multiset<string> x, y;
    string xx = "";
    for (int i = 0; i < n - 1; i++) {
      xx += k[i];   
      x.insert(xx);
    }
    string yy = "";
    for (int i = n - 1; i > 0; i--) {
      yy = k[i] + yy;
      y.insert(yy);
    }
    for (int i = 0; i < 2 * n - 2; i++) {
      if (x.count(s[i]) > 0) {
        x.erase(x.find(s[i]));
        ans += 'P';
      } else {
        if (y.count(s[i]) > 0) {
          y.erase(y.find(s[i]));
          ans += 'S';
        } else {
          return false;
        }
      }
    }
    return true;
  };
  if (Solve(t[0], t[1])) {
    cout << ans << '\n';  
  } else {
    Solve(t[1], t[0]);
    cout << ans << '\n';
  }
  return 0;
}