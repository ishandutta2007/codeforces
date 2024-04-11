/**
 *    author:  tourist
 *    created: 29.04.2018 16:25:11       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  vector<int> x(2);
  cin >> n >> x[0] >> x[1];
  vector< pair<int,int> > c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i].first;
    c[i].second = i;
  }
  sort(c.rbegin(), c.rend());
  for (int rot = 0; rot < 2; rot++) {
    int use = -1;
    for (int i = 0; i < n; i++) {
      if (x[0] <= (long long) c[i].first * (i + 1)) {
        use = i + 1;
        break;
      }
    }
    if (use != -1) {
      int use2 = -1;
      for (int i = use; i < n; i++) {
        if (x[1] <= (long long) c[i].first * (i - use + 1)) {
          use2 = i - use + 1;
          break;
        }
      }
      if (use2 != -1) {
        cout << "Yes" << '\n';
        vector< vector<int> > res(2);
        for (int i = 0; i < use; i++) {
          res[rot].push_back(c[i].second);
        }
        for (int i = 0; i < use2; i++) {
          res[rot ^ 1].push_back(c[use + i].second);
        }
        cout << (int) res[0].size() << " " << (int) res[1].size() << '\n';
        for (int q = 0; q < 2; q++) {
          for (int i = 0; i < (int) res[q].size(); i++) {
            if (i > 0) {
              cout << ' ';
            }
            cout << res[q][i] + 1;
          }
          cout << '\n';
        }
        return 0;
      }
    }
    swap(x[0], x[1]);
  }
  cout << "No" << '\n';
  return 0;
}