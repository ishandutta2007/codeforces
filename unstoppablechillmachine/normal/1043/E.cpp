#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

struct T {
  int x, y, id;
};

bool cmp(T a, T b) {
  return a.x - a.y < b.x - b.y;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<T> a(n);
  vector<int> xx(n), yy(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
    xx[i] = a[i].x;
    yy[i] = a[i].y;
    a[i].id = i;
  }
  sort(all(a), cmp);
  vector<int> sum(n);
  vector<int> pref(n), suf(n);
  pref[0] = a[0].x;
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + a[i].x;
  }
  suf[n - 1] = a[n - 1].y;
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = suf[i + 1] + a[i].y;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      sum[a[i].id] += i * a[i].y + pref[i - 1];
    }
    if (i + 1 < n) {
      sum[a[i].id] += (n - i - 1) * a[i].x + suf[i + 1];
    }
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    sum[a] -= min(xx[a] + yy[b], xx[b] + yy[a]);
    sum[b] -= min(xx[a] + yy[b], xx[b] + yy[a]);
  }
  for (int i = 0; i < n; i++) {
    cout << sum[i] << ' ';
  }
  cout << '\n';
}