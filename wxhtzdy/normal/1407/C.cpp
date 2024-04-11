/**
 *  author: milos
 *  created: 04.01.2021 00:37:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int j = 0;
  vector<int> ans(n);
  auto Ask = [&](int x, int y) {
    cout << "? " << x + 1 << " " << y + 1 << endl;  
    int t;
    cin >> t;
    return t;
  };
  for (int i = 1; i < n; i++) {
    int x = Ask(j, i), y = Ask(i, j);      
    if (x < y) {
      ans[i] = y;     
    } else {
      ans[j] = x;
      j = i; 
    }
  }
  ans[j] = n;
  cout << "! ";
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  return 0;
}