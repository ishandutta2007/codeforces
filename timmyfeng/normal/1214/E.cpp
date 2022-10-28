#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

pair<int, int> d[N];
vector<int> todo[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> d[i].first;
    d[i].second = i;
  }
  sort(d + 1, d + n + 1, greater<pair<int, int>>());

  int par = 0;
  for (int i = 1; i <= n || !todo[i].empty(); ++i) {
    for (int j : todo[i]) {
      cout << par << " " << j << "\n";
    }
    if (i <= n) {
      todo[i + d[i].first].push_back(d[i].second * 2);
      if (par > 0) {
        cout << par << " " << d[i].second * 2 - 1 << "\n";
      }
      par = d[i].second * 2 - 1;
    } else {
      par = todo[i][0];
    }
  }
}