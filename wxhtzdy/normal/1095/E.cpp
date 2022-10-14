/**
 *  author: milos
 *  created: 26.12.2020 22:04:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int bal = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    bal += (s[i] == '(' ? 1 : -1);
    a[i] = bal;
  }
  vector<int> suf(n);
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = a[i];
    if (i < n - 1) {
      suf[i] = min(suf[i], suf[i + 1]);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    bool ok = true;
    if (s[i] == '(' && a[n - 1] != 2) {
      ok = false;
    }
    if (s[i] == ')' && a[n - 1] != -2) {
      ok = false;
    }            
    if (s[i] == '(' && suf[i] < 2) {
      ok = false;
    }
    if (s[i] == ')' && suf[i] < -2) {
      ok = false;  
    }
    ans += ok;
    if (a[i] < 0) {
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}