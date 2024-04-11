/**
 *    author:  milos
 *    created: 10.03.2021 13:36:27       
**/
#include <bits/stdc++.h>
 
using namespace std;

vector<double> x, y;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);                      
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;                          
    for (int i = 0; i < n * 2; i++) {
      int a, b;
      cin >> a >> b;
      if (a == 0) {
        y.push_back(abs(b));
      } else {
        x.push_back(abs(a));
      }
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    double ans = 0;
    for (int i = 0; i < n; i++) {
      ans += sqrt(x[i] * x[i] + y[i] * y[i]);
    }
    cout << fixed << setprecision(15);
    cout << ans << '\n';
    x.clear();
    y.clear();
  }
  return 0;
}