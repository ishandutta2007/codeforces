#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5, maxm = 100000 + 5;
int n, m, dx, dy, y[maxn], cnt[maxn];
struct Point { int x, y; } p[maxm];

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m >> dx >> dy;
  for (int i = 0; i < m; ++i) cin >> p[i].x >> p[i].y;
  for (int i = 0; i < n; ++i) y[(ll)dx * (ll)i % n] = (ll)i * (ll)dy % n;
  for (int i = 0; i < m; ++i) cnt[(p[i].y - y[p[i].x] + n) % n]++;
  int Max = 0, ans = -1;
  for (int i = 0; i < n; ++i) if (cnt[i] > Max) Max = cnt[i], ans = i;
  cout << 0 << ' ' << ans << '\n';
}