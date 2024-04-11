/**
 *    author:  tourist
 *    created: 18.06.2020 17:49:51       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int k = n + 2;
  vector<pair<int, int>> ret;
  for (int i = 0; i < k; i++) {
    for (int j = i - 1; j <= i + 1; j++) {
      if (j >= 0 && j < k) {
        ret.emplace_back(i, j);
      }
    }
  }
  cout << ret.size() << '\n';
  for (auto& p : ret) {
    cout << p.first << " " << p.second << '\n';
  }
  return 0;
}