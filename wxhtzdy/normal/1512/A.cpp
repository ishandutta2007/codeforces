/**
 *    author:  milos
 *    created: 10.04.2021 18:20:28       
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
    const int MAX = 105;
    vector<int> cnt(MAX);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
      if (cnt[a[i]] == 1) {
        cout << i + 1 << '\n';
        break;
      }
    }
  }
  return 0;
}