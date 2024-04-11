/**
 *    author:  wxhtzdy
 *    created: 09.08.2022 13:25:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  vector<int> x(3), y(3); 
  for (int i = 0; i < 3; i++) {
    cin >> x[i] >> y[i];
  }
  vector<int> order(3);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return (x[i] < x[j]) || (x[i] == x[j] && y[i] < y[j]);
  });
  int mn = *min_element(y.begin(), y.end());
  int mx = *max_element(y.begin(), y.end());
  cout << 3 << '\n';
  cout << x[order[1]] << " " << mn << " " << x[order[1]] << " " << mx << '\n';
  cout << x[order[0]] << " " << y[order[0]] << " " << x[order[1]] << " " << y[order[0]] << '\n';
  cout << x[order[2]] << " " << y[order[2]] << " " << x[order[1]] << " " << y[order[2]] << '\n';
  return 0;
}