/**
 *  author: milos
 *  created: 13.12.2020 16:49:39
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
  const int N = 1e5 + 5;
  int lst[N];
  for (int i = 0; i < N; i++) {
    lst[i] = -1e9;
  }
  for (int i = 0; i < n; i++) {
    vector<int> d; 
    for (int j = 2; j <= sqrt(x[i]); j++) {
      if (x[i] % j == 0) {
        d.push_back(j);
        if (j != sqrt(x[i])) {
          d.push_back(x[i] / j);
        }
      }
    }
    d.push_back(1);    
    if (x[i] != 1) d.push_back(x[i]);
    int ans = 0;
    for (int j : d) {
      if (i - y[i] > lst[j]) {
        ans++;
      }
    }
    cout << ans << '\n';
    for (int c : d) {
      lst[c] = i;
    }
  }
  return 0;
}