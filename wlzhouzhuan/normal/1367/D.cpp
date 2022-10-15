// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define debug(x) cerr << #x << " = " << x << '\n';
#define pll pair <ll, ll>

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

const int N = 1000;
char s[N], ans[N];
int cnt[N], b[N], n, m;
int vis[N];

void solve() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  scanf("%d", &m);
  for (rint i = 1; i <= m; i++) scanf("%d", &b[i]);
  for (rint i = 0; i < 26; i++) cnt[i] = 0;
  for (rint i = 1; i <= n; i++) cnt[s[i] - 'a']++;
  int now = 25;
  for (rint i = 1; i <= n; i++) vis[i] = 0;
  while (true) {
    vector <int> id;
    for (rint i = 1; i <= m; i++) {
      if (!vis[i] && !b[i]) {
        id.pb(i);
        vis[i] = 1;
      }
    }  
    if (id.empty()) break;
    while (cnt[now] < id.size()) now--;
    for (auto v: id) {
      for (rint i = 1; i <= m; i++) {
        if (!vis[i]) b[i] -= abs(i - v);
      }
      ans[v] = now + 'a';
    }
    now--;
  }
  for (rint i = 1; i <= m; i++) putchar(ans[i]);
  puts("");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;  
}