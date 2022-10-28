#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<long long> a(n + 1);
  long long maxi = LLONG_MIN;
  map<long long, int> where;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
    if (a[i] > maxi)
      maxi = a[i], where[maxi] = i - 1;
  }

  while (m--) {
    long long x;
    cin >> x;

    if (x <= maxi) {
      cout << where.lower_bound(x)->second << " ";
    } else if (a[n] <= 0) {
      cout << -1 << " ";
    } else {
      long long k = (x - maxi + a[n] - 1) / a[n];
      cout << k * n + where.lower_bound(x - a[n] * k)->second << " ";
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
    solve();
}