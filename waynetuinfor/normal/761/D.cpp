#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 100000 + 5;

struct S {
  int n, i;
  bool operator<(const S& rhs) const {
    return n < rhs.n;
  }
} p[maxn];

int n, l, r, a[maxn], c[maxn];

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> l >> r;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> p[i].n, p[i].i = i;
  sort(p, p + n);
  int x = l - r;
  for (int i = 0; i < n; ++i) {
    if (x > r - l) { cout << "-1\n"; return 0; }
    if (x + a[p[i].i] < l || x + a[p[i].i] > r) {
      if (l - a[p[i].i] > x) x = l - a[p[i].i];
      else if (r - a[p[i].i] > x) x = r - a[p[i].i];
      else { cout << "-1\n"; return 0; }
    }
    c[p[i].i] = x++;
  }
  for (int i = 0; i < n; ++i) if (a[i] + c[i] < l || a[i] + c[i] > r) { cout << "-1\n"; return 0; }
  for (int i = 0; i < n; ++i) cout << a[i] + c[i] << ' ';
  return 0;
}