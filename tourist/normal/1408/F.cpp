/**
 *    author:  tourist
 *    created: 30.09.2020 18:05:13       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int p = 1;
  while (2 * p <= n) {
    p *= 2;
  }
  vector<pair<int, int>> ret;
  function<void(int, int)> Make = [&](int from, int to) {
    if (from == to) {
      return;
    }
    int mid = (from + to) >> 1;
    Make(from, mid);
    Make(mid + 1, to);
    int i = from;
    int j = mid + 1;
    while (i <= mid) {
      ret.emplace_back(i, j);
      i += 1;
      j += 1;
    }
  };
  Make(0, p - 1);
  if (p < n) {
    Make(n - p, n - 1);
  }
  cout << ret.size() << '\n';
  for (auto& p : ret) {
    cout << p.first + 1 << " " << p.second + 1 << '\n';
  }
  return 0;
}