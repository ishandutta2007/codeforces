/**
 *    author:  tourist
 *    created: 13.06.2021 20:20:03       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return x[i] + y[i] < x[j] + y[j];
  });
  multiset<long long> L, R;
  long long deltaR = 0;
  L.insert(0);
  R.insert(0);
  long long ans = 0;
  long long last = 0;
  for (int i : order) {
    {
      long long extra = x[i] + y[i] - last;
      deltaR += extra;
      last = x[i] + y[i];
    }
    {
      auto itL = prev(L.end());
      if (x[i] <= *itL) {
        ans += (*itL) - x[i];
        R.insert((*itL) - deltaR);
        L.erase(itL);
        L.insert(x[i]);
        L.insert(x[i]);
        continue;
      }
    }
    {
      auto itR = R.begin();
      if (x[i] >= (*itR) + deltaR) {
        ans += x[i] - ((*itR) + deltaR);
        L.insert((*itR) + deltaR);
        R.erase(itR);
        R.insert(x[i] - deltaR);
        R.insert(x[i] - deltaR);
        continue;
      }
    }
    L.insert(x[i]);
    R.insert(x[i] - deltaR);
  }
  cout << ans << '\n';
  return 0;
}