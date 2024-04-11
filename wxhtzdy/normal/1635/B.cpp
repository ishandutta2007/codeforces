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
    auto Is = [&](int id) {
      return a[id] > a[id - 1] && a[id] > a[id + 1];
    };          
    int ans = 0;
    for (int i = 2; i < n; i++) {
      if (Is(i - 1)) {
        a[i] = a[i - 1];   
        if (i + 1 < n && a[i] < a[i + 1]) {
          a[i] = a[i + 1];
        }
        ans += 1;
      }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << a[i];
    }
    cout << '\n';
  }                                                                    
  return 0;
}