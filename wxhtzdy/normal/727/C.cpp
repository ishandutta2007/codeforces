/**
 *    author:  milos
 *    created: 26.04.2021 00:56:08       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto Ask = [&](int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int x;
    cin >> x;
    return x; 
  };
  int x = Ask(0, 1);
  int y = Ask(1, 2);
  int z = Ask(0, 2);
  vector<int> ans(n);
  ans[1] = (x + y - z) / 2;
  ans[0] = x - ans[1];
  ans[2] = y - ans[1];
  for (int i = 3; i < n; i++) {
    ans[i] = Ask(0, i) - ans[0];
  }        
  cout << "! ";
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}