/**
 *    author:  milos
 *    created: 21.02.2021 15:02:42       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, a;
  cin >> n >> k >> a;
  int m;
  cin >> m;
  vector<int> x(m);
  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }
  auto Can = [&](int j) {
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < j; i++) {
      cnt[x[i]]++;
    }
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + cnt[i];  
    }
    int curr = 0;
    for (int i = 0; i + a <= n; i++) {
      if (pref[i] == pref[i + a]) {
        i += a;
        curr++;
        if (curr == k) {
          return true;
        }
      }
    }            
    if (curr == k) {
      return true;
    } else {
      return false;
    }
  };
  if (Can(m)) {
    cout << -1 << '\n';
    return 0;
  }
  int bot = 0, top = m;
  while (bot + 1 < top) {
    int mid = bot + top >> 1;
    if (Can(mid)) {
      bot = mid;  
    } else {
      top = mid;
    }
  }
  cout << top << '\n';
  return 0;
}