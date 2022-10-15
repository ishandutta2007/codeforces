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

const int N = 505;

pii a[N];
int p[N], n;

void rotate(int x) {
  swap(p[x], p[x + 2]);
  swap(p[x + 1], p[x + 2]);
}
bool check() {
  for (rint i = 1; i < n; i++) {
    if (p[i] > p[i + 1]) {
      return 0;
    }
  }
  return 1;
}

void solve() {
  n = read();
  for (rint i = 1; i <= n; i++) {
    int x = read();
    a[i] = make_pair(x, i);
  } 
  sort(a + 1, a + n + 1);
  for (rint i = 1; i <= n; i++) {
    p[a[i].second] = i;
  }
  int cnt = 0;
  for (rint i = 1; i <= n; i++) {
    for (rint j = i + 1; j <= n; j++) {
      if (p[i] > p[j]) {
        cnt++;
      }
    }
  }  
  if (cnt & 1) {
    for (rint i = 1; i < n; i++) {
      if (a[i].first == a[i + 1].first) {
        swap(p[a[i].second], p[a[i + 1].second]);
        break;
      }
    }
  }
  //printf(" *** debug\n");
  //for (rint i = 1; i <= n; i++) {
  //  printf("%d ", p[i]);
  //}
  //puts("");
  
  vector <int> ans;
  for (rint i = 1; i <= n - 2; i++) {
    int pos = min_element(p + i, p + n + 1) - p;
    //printf("current i = %d, pos = %d\n >>>> ", i, pos);
    //for (rint i = 1; i <= n; i++) printf("%d ", p[i]);
    //puts(""); 
    while (pos > i + 1) {
      rotate(pos - 2), ans.pb(pos - 2);
      pos -= 2;
    }
    if (pos > i) {
      rotate(i), ans.pb(i);
      rotate(i), ans.pb(i);
    }
  }
  /* 
  for (rint i = 0; i < 3; i++) {
    if (check()) break;
    rotate(n - 2), ans.pb(n - 2);
  }
  */
  if (!check()) {
    puts("-1");
  } else {
    printf("%d\n", (int)ans.size());
    for (auto v: ans) {
      printf("%d ", v);
    }
    puts("");
  }
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}