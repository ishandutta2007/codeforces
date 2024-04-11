/**
 *    author:  milos
 *    created: 23.02.2021 09:25:41       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ans;
  for (int i = 0; i < 100; i++) {
    int x = n - i;
    if (x < 0) {
      break;
    }         
    int sum = 0;
    while (x > 0) {
      sum += x % 10;
      x /= 10;
    }
    if (sum + n - i == n) {
      ans.push_back(n - i);
    }
  }
  sort(ans.begin(), ans.end());
  cout << (int) ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    if (i > 0) {
      cout << '\n';
    }
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}