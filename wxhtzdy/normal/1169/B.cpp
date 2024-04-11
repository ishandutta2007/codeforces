/**
 *  author: milos
 *  created: 08.01.2021 11:59:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    --a[i], --b[i];
  }
  {
    int x = a[0];
    vector<int> cnt(n, 0);
    int sum = 0;
    for (int i = 1; i < m; i++) {
      if (a[i] != x && b[i] != x) {
        cnt[a[i]] += 1;
        cnt[b[i]] += 1;
        sum += 1;
      }
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (cnt[i] >= sum) {
        ok = true;
      }
    }
    if (ok) {
      cout << "YES" << '\n';
      return 0;
    }
  }
  {
    int x = b[0];  
    vector<int> cnt(n, 0);
    int sum = 0;
    for (int i = 1; i < m; i++) {
      if (a[i] != x && b[i] != x) {
        cnt[a[i]] += 1;
        cnt[b[i]] += 1;
        sum += 1;
      }
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (cnt[i] >= sum) {
        ok = true;
      }
    }
    if (ok) {
      cout << "YES" << '\n';
      return 0;
    }
  }
  cout << "NO" << '\n';
  return 0;
}