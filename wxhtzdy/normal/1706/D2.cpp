/**
 *    author:  wxhtzdy
 *    created: 18.07.2022 17:04:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = 100005;
  vector<int> pref(MAX);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }                
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    fill(pref.begin(), pref.end(), MAX);
    vector<int> xs;
    vector<int> ys;
    vector<int> b;
    for (int i = 0; i < n; i++) {
      xs.clear();
      ys.clear();
      b.clear();
      if (a[i] < k) {
        ys.push_back(0);
      }
      for (int x = 1; x * x <= a[i]; x++) {
        if (x <= k) {
          xs.push_back(a[i] / x);
        }
        if (a[i] > x && a[i] / (x + 1) + 1 <= k) {
          ys.push_back(x);
        }
      }
      reverse(xs.begin(), xs.end());
      int xa = (int) xs.size();
      int ya = (int) ys.size();
      int x = 0;
      int y = 0;   
      while (x < xa || y < ya) {
        if (x < xa && (y >= ya || xs[x] <= ys[y])) {
          b.push_back(xs[x++]); 
        } else {
          b.push_back(ys[y++]);
        }
      }        
      b.push_back(MAX);
      if (b[0] > 0) {
        pref[b[0] - 1] = -MAX;
      }
      for (int j = 0; j + 1 < (int) b.size(); j++) {
        int L = b[j];
        int R = b[j + 1] - 1;
        if (L > R) {
          continue;
        }
        pref[R] = min(pref[R], L);
      }
    }
    int ans = a[n - 1] - a[0];
    for (int i = MAX - 2; i >= 0; i--) {
      pref[i] = min(pref[i], pref[i + 1]);
      ans = min(ans, i - pref[i]);  
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}