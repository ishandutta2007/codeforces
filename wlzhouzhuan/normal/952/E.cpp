#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rll RE ll
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i != -1; i = edge[i].nxt)
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second

template <typename T>
void read(T &x) {
  x = 0; char op = getchar(); int F = 1;
  while (!isdigit(op)) {
    if (op == '-') F *= -1; op = getchar();
  }
  while (isdigit(op)) {
    x = (x << 1) + (x << 3) + op - '0'; op = getchar();
  }
  x *= F;
}

template <typename T, typename ...Args>
void read(T &x, Args &...args) {
  read(x); read(args...);
}

template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

template <typename T1, typename T2>
void ckmin(T1 &x, T2 y) {
  if (x > y) x = y;
}

int n, s1 = 0, s2 = 0;

int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    string tmp, kinds;
    cin >> tmp >> kinds;
    if (kinds == "hard") s1++;
    else s2++;
  }
  if (s1 > s2) swap(s1, s2);

  ll l = 1, r = 1e9;
  while (l < r) {
    ll mid = (l + r) >> 1;
    if (mid * mid / 2 < s1 || (mid * mid + 1) / 2 < s2)
      l = mid + 1;
    else
      r = mid;
  } 
  printf("%lld\n", l);

  return 0;
}