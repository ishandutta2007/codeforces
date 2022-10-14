#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);        
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> cnt(m, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i] - 1]++;
  }
  long long ans = 0, ns = n;
  for (int i = 0; i < m; i++) {
    ns -= cnt[i];
    ans += cnt[i] * ns;      
  }
  cout << ans << '\n';
  return 0;
}