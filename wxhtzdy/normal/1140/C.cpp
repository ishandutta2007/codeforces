#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a.begin(), a.end());
  multiset<int> s;
  long long ans = 0, sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    sum += a[i].second;
    s.insert(a[i].second);
    if ((int) s.size() > k) {
      sum -= *s.begin();
      s.erase(s.begin());
    }
    ans = max(ans, (long long) (sum * a[i].first));
  }
  cout << ans << '\n';
  return 0;
}