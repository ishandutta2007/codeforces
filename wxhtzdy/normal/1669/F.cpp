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
    long long t = accumulate(a.begin(), a.end(), 0);         
    map<long long, int> have;
    long long s = 0;
    for (int i = n - 1; i >= 0; i--) {
      s += a[i];
      have[s] = max(have[s], n - i);
    }
    s = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      s += a[i];
      if (s * 2 <= t && have.count(s)) {
        ans = max(ans, i + 1 + have[s]);
      }
    }
    cout << min(ans, n) << '\n';
  }                                                                    
  return 0;
}