/**
 *    author:  milos
 *    created: 30.03.2021 20:25:31       
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
    vector<int> cnt(2);
    for (int i = 0; i < n; i++)  {
      cin >> a[i];
      cnt[a[i] % 2] += 1;  
    }
    if (cnt[1] % 2 == 1) {
      cout << "YES" << '\n';
    } else {
      cout << (min(cnt[0], cnt[1]) > 0 ? "YES" : "NO") << '\n';
    }
  }
  return 0;
}