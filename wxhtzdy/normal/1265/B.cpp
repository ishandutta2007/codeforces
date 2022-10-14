#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> pos;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pos[a[i]] = i;
    }
    vector<long long> pref(n);
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        pref[i] = a[i];
      } else {
        pref[i] = pref[i - 1] + a[i];
      }
    }
    int l = pos[1], r = pos[1];
    for (long long i = 1; i <= n; i++) {
      l = min(l, pos[i]);
      r = max(r, pos[i]);
      long long sum = pref[r] - (l == 0 ? 0 : pref[l - 1]), len = i;
      if (sum == (len * (len + 1) / 2)) {
        cout << 1;
      } else {
        cout << 0;
      }
      //cout << sum << " " << l << " " << r << endl;
    } 
    cout << '\n';
  }
  return 0;
}