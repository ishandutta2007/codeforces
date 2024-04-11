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
    vector<int> cnt(n + 1);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      long long s = 0;
      for (int j = i + 1; j < n; j++) {
        if (a[i] > a[j]) {
          ans += s;
        }
        s += cnt[a[j]];
      }
      for (int j = a[i] + 1; j <= n; j++) {
        cnt[j] += 1;
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}