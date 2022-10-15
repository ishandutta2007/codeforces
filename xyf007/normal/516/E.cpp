#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N = 2 * 1e5 + 100;
int n, m;
vector<int> oa, ob, p[N];
inline void ckmin(int &a, int b) { a = ((a < b) ? a : b); }
inline void ckmax(int &a, int b) { a = ((a > b) ? a : b); }
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
void exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a % b, x, y);
  int z = x;
  x = y;
  y = z - (a / b) * y;
}
int work(int a, int b, int c) {
  int g = __gcd(a, b);
  assert(c % g == 0);
  a /= g;
  b /= g;
  c /= g;
  int x, y;
  exgcd(a, b, x, y);
  x *= c;
  y *= c;
  return (x % b + b) % b;
}
signed main() {
  n = read();
  m = read();
  int k = read();
  oa.resize(k);
  for (int i = 0; i < k; i++) oa[i] = read();
  k = read();
  ob.resize(k);
  for (int i = 0; i < k; i++) ob[i] = read();
  if (n < m) swap(oa, ob), swap(n, m);
  if (len(oa) == n && len(ob) == m) {
    printf("0\n");
    return 0;
  }
  sort(oa.begin(), oa.end());
  reverse(oa.begin(), oa.end());
  int cnt = n - 1, ans = 0;
  for (int i : oa) {
    if (i == cnt)
      cnt--;
    else
      break;
  }
  ans = max(ans, cnt);
  sort(ob.begin(), ob.end());
  reverse(ob.begin(), ob.end());
  cnt = m - 1;
  for (int i : ob) {
    if (i == cnt)
      cnt--;
    else
      break;
  }
  ans = max(ans, cnt);
  oa.insert(oa.end(), ob.begin(), ob.end());
  sort(oa.begin(), oa.end());
  oa.resize(unique(oa.begin(), oa.end()) - oa.begin());
  int g = __gcd(n, m);
  if (g > len(oa)) {
    printf("-1\n");
    return 0;
  }
  for (int i : oa) p[i % g].push_back(i);
  for (int i = 0; i < g; i++) {
    if (p[i].empty()) {
      printf("-1\n");
      return 0;
    }
    if (len(p[i]) == n / g) continue;
    vector<pair<int, int>> tmp;
    for (int j : p[i]) tmp.emplace_back(work(m, n, j - i), j);
    sort(tmp.begin(), tmp.end());
    tmp.emplace_back(tmp[0].first + n / g, tmp[0].second);
    for (int j = 0; j < len(tmp) - 1; j++) {
      auto [pos, id] = tmp[j];
      ckmax(ans, id + (tmp[j + 1].first - 1 - pos) * m);
    }
  }
  printf("%lld\n", ans);
  return 0;
}