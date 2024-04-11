/**
 *  author: milos
 *  created: 11.12.2020 16:42:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    double win = 0, lose = 1;
    int j = -1;
    for (int i = 1; i < n; i++) {
      if (a[i] != i + 1) {
        j = i;
      }
    }
    //cout << j << endl; 
    for (int i = 0; i < m; i++) {
      int l;
      cin >> l;
      double p;
      cin >> p;
      if (l > j) {
        double k = lose * p;
        win += k;
        lose -= k;    
      }
    }
    if (j == -1) win = 1;
    cout << fixed << setprecision(6) << win << '\n';
  }
  return 0;
}