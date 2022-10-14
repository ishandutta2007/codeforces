/**
 *    author:  wxhtzdy
 *    created: 06.08.2022 16:34:17
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
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }       
    x.push_back(0);
    y.push_back(0);
    int X = *max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end());
    int Y = *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end());
    cout << X * 2 + Y * 2 << '\n';
  }                                                                  
  return 0;
}