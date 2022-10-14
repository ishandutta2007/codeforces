/**
 *    author: m371
 *    created: 07.11.2021 14:42:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
  }
  vector<int> sz;
  vector<bool> was(n, false);
  for (int i = 0; i < n; i++) {
    if (was[i]) {
      continue;
    }      
    int j = i, cnt = 0;
    while (!was[j]) {
      was[j] = true;
      cnt += 1;
      j = p[j];
    }
    sz.push_back(cnt);
  }                
  sort(sz.rbegin(), sz.rend());
  if (sz.size() == 1) {
    cout << (long long) sz[0] * sz[0] << '\n';
  } else {
    if (sz.size() == 2) {
      sz[0] += sz[1];
      cout << (long long) sz[0] * sz[0] << '\n';
    } else {
      long long ans = (long long) (sz[0] + sz[1]) * (sz[0] + sz[1]);
      for (int i = 2; i < sz.size(); i++) {
        ans += (long long) sz[i] * sz[i]; 
      }
      cout << ans << '\n';
    }  
  }
  return 0;
}