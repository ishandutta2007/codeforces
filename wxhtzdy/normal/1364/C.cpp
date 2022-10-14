/**
 *  author: milos
 *  created: 03.10.2020 00:45:39
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
  vector<int> b;
  for (int i = 0; i <= n; i++) {
    if (i != a[n - 1]) {
      b.push_back(i);
    }
  }
  vector<int> c(n, -1);
  map<int, int> was;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != a[i + 1]) {
      c[i + 1] = a[i];
      was[a[i]] = 1;
    }
  }
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] != -1) {
      continue;
    }
    while (j < (int) b.size() && was[b[j]] == 1) {
      j++;
    }
    c[i] = b[j];
    j++;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << c[i];
  }
  return 0;
}