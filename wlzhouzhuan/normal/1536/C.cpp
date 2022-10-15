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

const int N = 500005;
char a[N];
int n;

void solve() {
  map<pii, int> Map;
  int res = 0;
  auto push = [&](int x, int y) {
    int t = __gcd(x, y);
    x /= t, y /= t;
//    printf("push %d %d\n", x, y);
    return ++Map[{x, y}];
  };
  scanf("%d%s", &n, a + 1);
  bool flag = 1;
  int x = 0, y = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[1] && flag) {
      printf("%d ", i);
      if (a[i] == 'D') x++;
      else y++;
    } else {
      flag = 0;
      if (a[i] == 'D') x++;
      else y++;
      printf("%d ", push(x, y));
    }
  } 
  puts("");
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}