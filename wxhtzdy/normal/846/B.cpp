#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, k, m;
  cin >> n >> k >> m;
  vector<ll> a(k);
  for (int i = 0; i < k; i++) cin >> a[i];
  ll s = accumulate(a.begin(), a.end(), 0LL);
  sort(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    ll x = i * (k + 1);
    ll ima = m - s * i;
    if (ima < 0) {
      break;
    }
    for (int j = 0; j < k; j++) {
      for (int l = i; l < n; l++) {
        if (ima >= a[j]) {
          x++;
          ima -= a[j];
        }
      }
    }
    ans = max(ans, x);
  }
  cout << ans << '\n';
}