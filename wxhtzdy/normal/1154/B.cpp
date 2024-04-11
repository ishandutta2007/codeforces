/**
 *  author: milos
 *  created: 17.12.2020 04:08:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sort(a.begin(), a.end());
  if (cnt.size() == 1) {
    cout << 0 << '\n';
    return 0;
  }
  if (cnt.size() == 2) {
    int diff = a[n - 1] - a[0];
    if (diff % 2 == 1) {
      cout << diff << '\n';
    } else {
      cout << diff / 2 << '\n';
    }
    return 0;
  }
  if (cnt.size() == 3) {
    int diff = a[n - 1] - a[0];
    if (diff % 2 == 0 && (cnt[a[0]] + cnt[a[0] + diff / 2] + cnt[a[n - 1]]) == n) {
      cout << diff / 2 << '\n';  
    } else {
      cout << -1 << '\n';
    }
  } else {
    cout << -1 << '\n';   
  }
  return 0;
}