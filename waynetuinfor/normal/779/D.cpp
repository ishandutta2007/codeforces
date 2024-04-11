#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
string p, t;
int a[maxn];

bool check(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> t >> p;
  for (int i = 0; i < t.length(); ++i) cin >> a[i];
  int d = 1, ans = 0;
  while (d <= t.length()) d <<= 1;
  while (d >>= 1) if (ans + d <= t.length()) if (check(ans + d)) ans += d;
  cout << ans + d << '\n';
  return 0;
}

bool check(int len) {
  int ind = 0;
  bool ban[maxn];
  memset(ban, false, sizeof(ban));
  for (int i = 0; i < len; ++i) ban[a[i] - 1] = true;
  for (int i = 0; i < t.length(); ++i) {
    if (ind == p.length()) break;
    if (ban[i]) continue;
    if (t[i] == p[ind]) ++ind;
  }
  return ind == p.length();
}