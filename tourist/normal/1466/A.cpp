/**
 *    author:  tourist
 *    created: 30.12.2020 17:34:56       
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
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        s.insert(x[j] - x[i]);
      }
    }
    cout << s.size() << '\n';
  }
  return 0;
}