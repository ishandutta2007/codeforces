#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int mx = *max_element(b.begin(), b.end());
  pair<long long, int> ans;
  ans.first = 1e18, ans.second = 1e9;
  for (int i = 0; i < n; i++) {
    for (long long j = 0; j < max((long long) a[i], (long long) t + mx); j++) {
      long long time = a[i] + j * b[i];
      if (time >= t) {
        if (time < ans.first) {
          ans.first = time;
          ans.second = i;
        }
        break;
      }
    }
  }
  cout << ans.second + 1 << '\n';
  return 0;
}