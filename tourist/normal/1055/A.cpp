/**
 *    author:  tourist
 *    created: 10.11.2018 17:39:58       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s;
  cin >> n >> s;
  s--;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  if (a[0]) {
    if (a[s]) {
      cout << "YES" << '\n';
      return 0;
    }
    if (b[s]) {
      for (int i = s + 1; i < n; i++) {
        if (a[i] + b[i] == 2) {
          cout << "YES" << '\n';
          return 0;
        }
      }
    }
  }
  cout << "NO" << '\n';
  return 0;
}