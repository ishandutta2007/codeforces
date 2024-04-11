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
    vector<vector<int>> cnt(2, vector<int>(2));
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[i % 2][x % 2] += 1;
    }
    bool ok = true;
    for (int i = 0; i < 2; i++) {
      ok &= (min(cnt[i][0], cnt[i][1]) == 0);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}