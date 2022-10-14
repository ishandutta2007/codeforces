#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, t;
  cin >> n >> t;

  vector<int> a(n);
  for (int &i : a) cin >> i;

  vector<ll> pref(n);
  for (int i = 0; i < n; i++) {
    pref[i] = a[i];
    if (i) pref[i] += pref[i - 1];
  }

  auto Can = [&](int x) {
    for (int i = 0; i <= n - x; i++) {
      if (pref[i + x - 1] - (i > 0 ? pref[i - 1] : 0) <= t) {
        return true;
      }
    }
    return false;
  };

  int bot = 1, top = n, ans = 0;
  while (bot <= top) {
    int mid = bot + top >> 1;
    if (Can(mid)) {
      ans = mid;
      bot = mid + 1;
    } else {
      top = mid - 1;
    }
  }
  cout << ans << '\n';
}