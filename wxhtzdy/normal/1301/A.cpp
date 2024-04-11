/**
 *    author:  milos
 *    created: 31.07.2020 12:01:59      
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 100050;

vector<vector<int>> g(N);

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string a, b, c;
    cin >> a >> b >> c;
    int n = (int) a.length();
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      if (c[i] != a[i] && c[i] != b[i]) ok = 0;
    }
    if (ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
  return 0;   
}