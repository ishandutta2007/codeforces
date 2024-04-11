/**
 *  author: milos
 *  created: 26.12.2020 01:09:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  vector<int> all;
  for (int c : s) {
    all.push_back(c);
  }
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
  }
  const int N = 2e3;
  int ans = N;
  for (int i = 0; i <= n; i++) {
    vector<int> cnt(N, 0);
    for (int j = 0; j < i; j++) {
      cnt[a[j]]++;
    }
    bool ok = true;
    for (int j = 0; j < N; j++) {
      if (cnt[j] > 1) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      break;
    }
    ans = min(ans, n - i);
    for (int j = n - 1; j > i; j--) {
      cnt[a[j]]++;
      if (cnt[a[j]] > 1) {
        break;
      }
      ans = min(ans, j - i); 
    }
  }
  cout << ans << '\n';
  return 0;
}