/**
 *    author:  tourist
 *    created: 30.05.2021 17:42:20       
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
    vector<int> a;
    for (int it = 0; it < n; it++) {
      int x;
      cin >> x;
      if (x > 1) {
        while (!a.empty() && a.back() + 1 != x) {
          a.pop_back();
        }
        assert(!a.empty());
        a.pop_back();
      }
      a.push_back(x);
      for (int j = 0; j < (int) a.size(); j++) {
        if (j > 0) {
          cout << ".";
        }
        cout << a[j];
      }
      cout << '\n';
    }
  }
  return 0;
}