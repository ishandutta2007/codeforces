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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < 0) {
        a[i] = -a[i];
        cnt += 1;
      }
    }
    for (int i = 0; i < cnt; i++) {
      a[i] = -a[i];
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}