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
#define SZ(a) ((int)(a.size()))
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

int ask(vector<int> a, vector<int> b) {
  printf("? %d %d\n", SZ(a), SZ(b));
  for (auto v: a) printf("%d ", v); puts("");
  for (auto v: b) printf("%d ", v); puts("");
  fflush(stdout);
  int x; scanf("%d", &x); return x;
}
int n;

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    vector<int> tag(n + 1, 0);
    int pos;
    for (int i = 2; i <= n; i++) {
      vector<int> a;
      rep(j, 1, i - 1) a.pb(j);
      if (ask(a, {i})) {
        pos = i;
        tag[i] = 1;
        break;
      }
    }
    for (int i = pos + 1; i <= n; i++) {
      if (ask({pos}, {i})) {
        tag[i] = 1;
      }
    }
    int l = 1, r = pos - 1;
    while (l < r) {
      int mid = l + r >> 1;
      vector<int> a;
      rep(i, 1, mid) a.pb(i);
      if (ask(a, {pos})) r = mid;
      else l = mid + 1;
    }
    tag[l] = 1;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      if (!tag[i]) {
        ans.pb(i);
      }
    }
    printf("! %d ", SZ(ans));
    for (auto v: ans) printf("%d ", v);
    puts("");
    fflush(stdout);
  }
  return 0;
}