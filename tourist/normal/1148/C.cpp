/**
 *    author:  tourist
 *    created: 01.06.2019 17:37:50       
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
    a[i]--;
  }
  vector<pair<int, int>> ret;
  {
    int i = 0, j = n - 1;
    while (i < n / 2) {
      while (i < n / 2 && a[i] < n / 2) {
        ++i;
      }
      while (j >= n / 2 && a[j] >= n / 2) {
        --j;
      }
      if (i < n / 2 && j >= n / 2) {
        if (j - i >= n / 2) {
          ret.emplace_back(i, j);
        } else {
          ret.emplace_back(i, n - 1);
          ret.emplace_back(0, n - 1);
          ret.emplace_back(0, j);
          ret.emplace_back(0, n - 1);
          ret.emplace_back(i, n - 1);
        }
        swap(a[i], a[j]);
      }
    }
  }
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    pos[a[i]] = i;
  }
  for (int i = 0; i < n / 2; i++) {
    if (pos[i] != i) {
      int j = pos[i];
      ret.emplace_back(i, n - 1);
      ret.emplace_back(j, n - 1);
      ret.emplace_back(i, n - 1);
      swap(a[i], a[j]);
      pos[a[i]] = i;
      pos[a[j]] = j;
    }
  }
  for (int i = n / 2; i < n; i++) {
    if (pos[i] != i) {
      int j = pos[i];
      ret.emplace_back(0, i);
      ret.emplace_back(0, j);
      ret.emplace_back(0, i);
      swap(a[i], a[j]);
      pos[a[i]] = i;
      pos[a[j]] = j;
    }
  }
  cout << ret.size() << '\n';
  for (auto& p : ret) {
    cout << p.first + 1 << " " << p.second + 1 << '\n';
  }
  return 0;
}