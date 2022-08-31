/**
 *    author:  tourist
 *    created: 13.03.2021 12:04:29       
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
  int mx = *max_element(a.begin(), a.end()) + 1;
  vector<int> p1(mx, -1);
  vector<int> p2(mx, -1);
  vector<int> p3(mx, -1);
  for (int i = 0; i < n; i++) {
    if (p1[a[i]] == -1) {
      p1[a[i]] = i;
      continue;
    }
    if (p2[a[i]] == -1) {
      p2[a[i]] = i;
      continue;
    }
    if (p3[a[i]] == -1) {
      p3[a[i]] = i;
      continue;
    }
    cout << "YES" << '\n';
    cout << p1[a[i]] + 1 << " " << p2[a[i]] + 1 << " " << p3[a[i]] + 1 << " " << i + 1 << '\n';
    return 0;
  }
  vector<int> ind;
  int two = -1;
  for (int i = 0; i < mx; i++) {
    if (p1[i] == -1) {
      continue;
    }
    ind.push_back(p1[i]);
    if (p2[i] == -1) {
      continue;
    }
    if (two != -1) {
      cout << "YES" << '\n';
      cout << p1[two] + 1 << " " << p1[i] + 1 << " " << p2[two] + 1 << " " << p2[i] + 1 << '\n';
      return 0;
    }
    two = i;
  }
  vector<pair<int, int>> met(2 * mx, make_pair(-1, -1));
  sort(ind.begin(), ind.end());
  if (two != -1) {
    met[two + two] = make_pair(p1[two], p2[two]);
  }
  for (int i = 0; i < (int) ind.size(); i++) {
    for (int j = i + 1; j < (int) ind.size(); j++) {
      int sum = a[ind[i]] + a[ind[j]];
      if (met[sum].first != -1) {
        cout << "YES" << '\n';
        cout << met[sum].first + 1 << " " << met[sum].second + 1 << " " << ind[i] + 1 << " " << ind[j] + 1 << '\n';
        return 0;
      }
      met[sum] = make_pair(ind[i], ind[j]);
    }
  }
  cout << "NO" << '\n';
  return 0;
}