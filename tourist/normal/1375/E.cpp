/**
 *    author:  tourist
 *    created: 04.07.2020 18:34:48       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  iota(b.begin(), b.end(), 0);
  sort(b.begin(), b.end(), [&](int i, int j) {
    if (a[i] != a[j]) {
      return a[i] < a[j];
    }
    return i < j;
  });
  vector<pair<int, int>> ret;
  for (int it = 0; it < n; it++) {
    for (int i = 0; i < n - 1; i++) {
      if (b[i] > b[i + 1]) {
        ret.emplace_back(b[i + 1], b[i]);
        swap(b[i], b[i + 1]);
      }
    }
  }
  cout << ret.size() << '\n';
  for (auto& p : ret) {
    cout << p.first + 1 << " " << p.second + 1 << '\n';
  }
  return 0;
}