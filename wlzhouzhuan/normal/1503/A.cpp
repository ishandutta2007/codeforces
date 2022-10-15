// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 200005;
char a[N], b[N], s[N];
int n;

bool check(char *bucket) {
  int cnt0 = 0;
  for (int i = 1; i <= n; i++) {
    if (bucket[i] == '(') cnt0++;
    else cnt0--;
    if (cnt0 < 0) return false;
  }
  return true;
}
void solve() {
  scanf("%d%s", &n, s + 1);
  int cnt1 = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') cnt1++;
  }
  if (cnt1 & 1) { puts("NO"); return ; }
  int now1 = 0, now2 = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') {
      now1++;
      if (now1 <= cnt1 / 2) a[i] = b[i] = '(';
      else a[i] = b[i] = ')';
    } else {
      now2++;
      if (now2 & 1) a[i] = '(', b[i] = ')';
      else a[i] = ')', b[i] = '(';
    }
  }
  if (check(a) && check(b)) {
    puts("YES");
    for (int i = 1; i <= n; i++) putchar(a[i]); puts("");
    for (int i = 1; i <= n; i++) putchar(b[i]); puts("");
  } else {
    puts("NO");
  }
}

int main() {
  int T;
  for (scanf("%d", &T); T; T--) solve();
  return 0;
}