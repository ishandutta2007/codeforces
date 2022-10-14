/**
 *    author:  wxhtzdy
 *    created: 14.06.2022 17:05:22
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
    vector<int> f(10);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      f[x % 10] += 1;
    }
    int ans = 0;           
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 10; k++) {
          vector<int> cnt(10);
          cnt[i] += 1;
          cnt[j] += 1;
          cnt[k] += 1;
          if ((i + j + k) % 10 == 3 && f[i] >= cnt[i] && f[j] >= cnt[j] && f[k] >= cnt[k]) {
            ans = 1;
          }
        }
      }  
    }   
    cout << (ans == 1 ? "YES" : "NO") << '\n';
  }
  return 0;
}