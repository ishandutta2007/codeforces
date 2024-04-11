%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
#define dd double
#define _i int
#define RE register
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define req(i, l, r) for (RE int i = l; i >= r; i--)
#define range(i, l, r) rep(i, l, r - 1)
#define Be(s, t) memset(s, t, sizeof(s))
#define poly vector <int>
#define pii pair <int, int>
template <typename T> void read(T &x) { x = 0; int FF = 1; char op = getchar(); while (!isdigit(op)) { if (op == '-') FF = -1; op = getchar(); } while (isdigit(op)) { x = (x << 1) + (x << 3) + op - '0'; op = getchar(); } x *= FF; }
template <typename T> void print(T x) { if (x < 0) { putchar('-'); x = -x; } if (x < 1) return ; print(x / 10); putchar(x % 10 + '0'); }
template <typename T> void print(T x, char _tab) { print(x); putchar(_tab); }

#define int long long
const int N = 1000005;
char s[N];
int ans, n;
int l[N], r[N];

signed main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    l[i] = l[i - 1];
    int j = i, cnt = 1;
    if (s[i] == 'o') continue;
    while (s[j + 1] == 'v') {
      cnt++; j++;
    }  
    l[j] = l[i] + (cnt - 1);
    i = j;
  }
  /*
  for (int i = 1; i <= n; i++)
    printf("%d ", l[i]);
  */
  for (int i = n; i >= 1; i--) {
    r[i] = r[i + 1];
    int j = i, cnt = 1;
    if (s[i] == 'o') continue;
    while (s[j - 1] == 'v') {
      cnt++; j--;
    }
    r[j] = r[i] + (cnt - 1);
    i = j;
  }
  unsigned long long ans = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] == 'o') ans += l[i] * r[i];
  printf("%llu\n", ans);
  return 0;
}