#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
    }
    if (s % n != 0) {
      cout << -1 << '\n';
      continue;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > s / n) ans++;
    }
    cout << ans << '\n';
  }
}