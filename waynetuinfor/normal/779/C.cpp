#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 200000 + 5;
int n, k, a[maxn], b[maxn], now;
long long ans;
vector<int> dis;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  dis.clear();
  for (int i = 0; i < n; ++i) {
    if (b[i] > a[i]) ans += a[i], ++now;
    else dis.push_back(i);
  }
  sort(dis.begin(), dis.end(), [](const int& A, const int& B) -> bool {
    return a[A] - b[A] < a[B] - b[B];
  });
  if (now < k) {
    for (int i = 0; i < k - now; ++i) ans += a[dis[i]];
    for (int i = k - now; i < dis.size(); ++i) ans += b[dis[i]];
  } else {
    for (int i = 0; i < dis.size(); ++i) ans += b[dis[i]];
  }
  cout << ans << '\n';
  return 0;
}