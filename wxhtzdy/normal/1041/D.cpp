#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, h;
  cin >> n >> h;
  vector<vector<int>> x(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    cin >> x[i][0] >> x[i][1];
  }
  vector<long long> pref(n);
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + x[i][0] - x[i - 1][1];
  }
  vector<long long> dx_pref(n);
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      dx_pref[i] = dx_pref[i - 1];
    }
    dx_pref[i] += x[i][1] - x[i][0];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int low = i, high = n - 1, pos;
    while (low <= high) {
      int mid = low + high >> 1;
      if (pref[mid] - pref[i] < h) {
        pos = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    long long tot = h + dx_pref[pos] - (i == 0 ? 0 : dx_pref[i - 1]);
    ans = max(ans, tot);
  }
  cout << ans << "\n";
  return 0;
}