/**
 *    author:  milos
 *    created: 23.03.2021 20:39:09       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = 4;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (max(a[2], a[3]) - 1 > min(a[2], a[3])) {
    cout << -1;
    return 0;
  }
  string ans = "";  
  vector<int> cnt(2, 0);
  if (a[2] > a[3]) {
    for (int i = 0; i < a[2]; i++) {
      ans += "47";
    }          
  } else {
    if (a[2] == a[3]) {
      if (a[0] > a[2]) {
        for (int i = 0; i < a[2]; i++) {
          ans += "47";
        }
        ans += '4';
      } else {
        if (a[1] > a[3]) {
          ans += '7';
          for (int i = 0; i < a[2]; i++) {
            ans += "47";
          }
        } else {
          cout << -1 << '\n';
          return 0;
        }
      }
    } else {
      for (int i = 0; i < a[3]; i++) {
        ans += "74";  
      }
    }
  }
  cnt[0] = cnt[1] = 0;
  for (char c : ans) {
    if (c == '4') cnt[0]++;
    if (c == '7') cnt[1]++;
  }
  if (cnt[0] > a[0] || cnt[1] > a[1]) {
    cout << -1 << '\n';
    return 0;
  }
  a[0] -= cnt[0];
  a[1] -= cnt[1];
  for (int i = 0; i < (int) ans.size(); i++) {
    if (ans[i] == '4' && a[0] > 0) {
      string nans = "";
      for (int j = 0; j <= i; j++) {
        nans += ans[j];
      }
      for (int j = 0; j < a[0]; j++) {
        nans += '4';
      }
      for (int j = i + 1; j < (int) ans.size(); j++) {
        nans += ans[j];
      }
      swap(ans, nans);
      break;
    }
  }
  for (int i = (int) ans.size() - 1; i >= 0; i--) {
    if (ans[i] == '7' && a[1] > 0) {
      string nans = "";
      for (int j = 0; j <= i; j++) {
        nans += ans[j];
      }
      for (int j = 0; j < a[1]; j++) {
        nans += '7';
      }
      for (int j = i + 1; j < (int) ans.size(); j++) {
        nans += ans[j];
      }               
      swap(ans, nans);
      break;          
    }
  }
  cout << ans << '\n';
  return 0;
}