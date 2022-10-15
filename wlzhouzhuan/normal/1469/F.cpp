// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { a > b && a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { a < b && a = b; }
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
multiset<pii> s;
int a[N], n, k;

bool check(int x) {
  s.clear();
  s.insert({0, 0});
  int white = 1;
  rep(i, 1, n) {
    auto it = s.begin(); s.erase(it);
    int l = it->fir, r = it->sec;
    if (l + 1 <= r) s.insert({l + 1, r});
    if (l <= x) white--;
    if (a[i] & 1) {
      s.insert({l + 2, l + 1 + a[i] / 2});
      if (l + 2 <= x) white += min(x, l + 1 + a[i] / 2) - l - 1;
      s.insert({l + 2, l + 1 + a[i] / 2});
      if (l + 2 <= x) white += min(x, l + 1 + a[i] / 2) - l - 1;
    } else {
      s.insert({l + 2, l + 1 + a[i] / 2 - 1});
      if (l + 2 <= x) white += min(x, l + 1 + a[i] / 2 - 1) - l - 1;
      s.insert({l + 2, l + 1 + a[i] / 2});
      if (l + 2 <= x) white += min(x, l + 1 + a[i] / 2) - l - 1;
    }
    if (white >= k) return 1;
  }
  return 0;
}

int main() {
  n = read(), k = read();
  rep(i, 1, n) a[i] = read();
  sort(a + 1, a + n + 1, greater<int>());
  int l = 0, r = 1e9 + 5;
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  printf("%d\n", l == 1e9 + 5 ? -1 : l);
  return 0;
}//