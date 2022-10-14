/**
 *    author:  wxhtzdy
 *    created: 19.07.2022 13:55:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  auto Ask = [&](vector<int> ids) {
    if (ids.empty()) {
      return vector<int>(n, (int) 1e9);
    }
    cout << ids.size() << endl;
    for (int i : ids) {
      cout << i + 1 << " ";
    }
    cout << endl;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    return b;
  };           
  vector<vector<vector<int>>> f(10, vector<vector<int>>(2, vector<int>(n)));
  for (int b = 0; b < 10; b++) {
    vector<int> xa;
    vector<int> xb;
    for (int i = 0; i < n; i++) {
      if (i >> b & 1) {
        xa.push_back(i);
      } else {
        xb.push_back(i);
      }
    }
    f[b][1] = Ask(xa);
    f[b][0] = Ask(xb);
  }
  cout << -1 << endl;
  for (int i = 0; i < n; i++) {
    int ans = 1e9;  
    for (int b = 0; b < 10; b++) {
      int p = (i >> b & 1);
      ans = min(ans, f[b][p ^ 1][i]);
    }
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}