/**
 *  author: milos
 *  created: 02.01.2021 00:28:26
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
    const int N = 2048 + 1;
    vector<int> cnt(N, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > 2048) {
        continue;
      }
      cnt[a[i]] += 1;
    }
    for (int i = 0; i < 2048; i++) {
      for (int j = 0; j < cnt[i] / 2; j++) {
        cnt[i * 2] += 1;  
      }
    }
    cout << (cnt[2048] >= 1 ? "YES" : "NO") << '\n';
  }
  return 0;
}