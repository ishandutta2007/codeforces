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

const int N = 2005;

int cnt[N];
char s[N];
int n, k;

bool check(int k, int turns) {
  for (rint i = 0; i < 26; i++) {
    k -= cnt[i] / turns;
    if (k <= 0) return 1;
  }
  return 0;
}

void solve() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  for (rint i = 0; i < 26; i++) cnt[i] = 0;
  for (rint i = 1; i <= n; i++) cnt[s[i] - 'a']++;
  sort(cnt, cnt + 26, greater <int> ());
  
  vector <int> inz;
  for (rint i = 1; i <= k; i++) {
    if (k % i == 0) inz.pb(i);
  }
  int anss = 0;
  for (auto t: inz) {
    int l = 1, r = n / t + 1, ans = 0;
    while (l < r) {
      int mid = l + r >> 1;
      //printf("> t = %d, mid = %d\n", t, mid);
      if (check(t, mid)) l = mid + 1, ans = mid;
      else r = mid;
    } 
    anss = max(anss, ans * t);
  }
  printf("%d\n", anss);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}