/**
 *  author: milos
 *  created: 30.12.2020 21:37:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);            
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }                      
    int N = 2 * n + 2;
    vector<int> cnt(N, 0);
    for (int i = 0; i < n; i++) {
      cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = N - 1; i >= 1; i--) {
      if (cnt[i] == 0) {
        continue;
      }
      if (cnt[i] == 1) {
        ans++;
        if (cnt[i + 1] == 0) {     
          swap(cnt[i], cnt[i + 1]);
          continue;
        }
      } else {
        if (cnt[i + 1] == 0) {
          ans += 2;
        } else {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}