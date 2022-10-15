// Author: wlzhouzhuan
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
#define poly vector<int>
#define SZ(x) (int(x.size()))
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

int now, flag;
int n;

int main() {
  int T;
  for (T = read(); T; T--) {
    set<int> s;
    n = read(), now = 0, flag = 1;
    for (int i = 1; i <= n; i++) {
      int x = read();
      if (!flag) continue;
      if (x > now) {
        auto it = s.upper_bound(now);
        if (it != s.end() && *it < x) flag = 0;
        else s.insert(x), now = x;
      } else {
        auto it = s.lower_bound(now);
        if (it != s.begin()) {
          --it;
          if (*it > x) flag = 0;
          else s.insert(x), now = x;
        } else {
          s.insert(x), now = x; 
        }
      }
    }
    puts(flag ? "YES" : "NO");
  }
}