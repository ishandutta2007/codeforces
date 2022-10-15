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
#define fir first
#define sec second

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
const int N = 300005;
char s[N];
int n; 
int main() {
  int T = read();
  while (T--) {
    scanf("%d%s", &n, s + 1);
    int more = 0, less = 0;
    for (int i = 1; i <= n; i++) {
      more |= s[i] == '>';
      less |= s[i] == '<';
    }
    if (!more || !less) {
      cout << n << '\n'; continue;
    }
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
      if (s[i] == '-') {
        ans[i] = ans[i % n + 1] = 1;
      }
    }
    int anss = 0;
    for (int i = 1; i <= n; i++) {
      if (ans[i]) {
        anss++;
      }
    }
    printf("%d\n", anss); 
  }
  return 0;
}