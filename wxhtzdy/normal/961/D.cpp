/**
 *    author: m371
 *    created: 11.10.2021 14:59:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  if (n <= 2) {
    cout << "YES" << '\n';
    return 0;
  }                       
  auto Ok = [&](int i, int j, int k) {
    long long a = x[i] * 1LL * (y[j] - y[k]) + x[j] * 1LL * (y[k] - y[i]) + x[k] * 1LL * (y[i] - y[j]);
    return a == 0;  
  };
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      vector<int> ids;
      for (int k = 0; k < n; k++) {
        if (k == i || k == j || Ok(i, j, k) || Ok(j, i, k) || Ok(i, k, j)) {
          
        } else {
          ids.push_back(k);
        }
      }          
      bool ok = true;
      for (int k = 2; k < ids.size(); k++) {
        if (!Ok(ids[0], ids[1], ids[k]) && !Ok(ids[1], ids[0], ids[k]) && !Ok(ids[0], ids[k], ids[1])) {
          ok = false;
        }
      }
      if (ok) {
        cout << "YES" << '\n';
        return 0;
      }
    } 
  }
  cout << "NO" << '\n';
  return 0;
}