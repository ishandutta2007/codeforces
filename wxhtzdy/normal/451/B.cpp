#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(v.begin(), v.end());
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[v[i].second] = i;
  }
  for (int i = 0; i < n; i++) {
    if (a[a[i]] != i) {
      cout << "no" << '\n';
      return 0;
    }
  }
  vector<pair<int, int>> r;
  for (int i = 0; i < n; i++) {
    if (a[i] == i) {
      continue;
    }
    r.emplace_back(i, a[i]);
    for (int j = i; j <= a[i]; j++) {
      if (a[j] == j && ((a[i] - i) % 2 == 1 || a[j] != i + (a[i] - i) / 2)) {
        cout << "no" << '\n';
        return 0;
      }
    }
    i = a[i];
  }
  if ((int) r.size() > 1) {
    cout << "no" << '\n';
    return 0;
  }
  cout << "yes" << '\n';
  if ((int) r.size() == 0) {
    cout << 1 << " " << 1;
  } else {
    cout << r[0].first + 1 << " " << r[0].second + 1;
  }
  return 0;
}