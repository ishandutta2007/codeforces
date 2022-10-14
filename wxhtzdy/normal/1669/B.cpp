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
      int x;
      cin >> x;
      a[x - 1] += 1;
    }
    int ans = -2;
    for (int i = 0; i < n; i++) {
      if (a[i] >= 3) {
        ans = i;
      }
    }
    cout << ans + 1 << '\n';
  }                                                                    
  return 0;
}