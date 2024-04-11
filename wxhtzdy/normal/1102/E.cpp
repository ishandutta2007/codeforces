#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> nxt(n);
  map<int, int> last;
  map<int, int> was;
  for (int i = n - 1; i >= 0; i--) {
    if (was[a[i]] == 0) {
      last[a[i]] = i;
      was[a[i]] = 1;
    }
    nxt[i] = last[a[i]];
  }
  long long ans = 1;
  int j = -1;
  for (int i = 0; i < n - 1; i++) {
    if (nxt[i] >= j) {
      j = nxt[i];
    }
    if (i == j) {
      ans *= 2;
      if (ans >= md) {
        ans %= md;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}