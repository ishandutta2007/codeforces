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
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]] += 1;
    }
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + cnt[i];
    }
    vector<int> nxt(n + 1);
    int pw = 1;
    for (int i = 0; i <= n; i++) {
      while (pw < i) {
        pw *= 2;
      }
      nxt[i] = pw - i;
    }
    auto Get = [&](int l, int r) {
      if (l > r) {
        return 0;
      }
      return pref[r] - pref[l - 1];
    };  
    int ans = nxt[n] + 2;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 30; j++) {
        // second group is of size 2 ^ j
        int sz = (1 << j);
        int low = i + 1, high = n, at = i + 1;
        while (low <= high) {
          int mid = (low + high) >> 1;
          if (Get(i + 1, mid) <= sz) {
            at = mid;
            low = mid + 1;  
          } else {
            high = mid - 1;  
          }
        }
        ans = min(ans, nxt[pref[i]] + nxt[Get(i + 1, at)] + nxt[n - Get(1, at)]);
      }
      for (int j = 0; j < 30; j++) {
        // third group is of size 2 ^ j
        int sz = (1 << j);
        int low = i + 1, high = n, at = n;
        while (low <= high) {
          int mid = (low + high) >> 1;
          if (Get(mid, n) <= sz) {
            at = mid;
            high = mid - 1;
          } else {
            low = mid + 1;
          }
        }
        ans = min(ans, nxt[pref[i]] + nxt[Get(at, n)] + nxt[n - pref[i] - Get(at, n)]);
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}