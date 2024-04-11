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
const int N = 105;
int a[N], ans[N];
int n, sum, sum2;
int cnt = 0;

void doit() {
  sum2 = a[1];
  for (int i = 2; i <= n; i++) {
    if (2 * a[i] <= a[1]) {
      sum2 += a[i]; ans[++cnt] = i;
    }
  }
}

void print() {
  if (sum / 2 + 1 <= sum2) {
    printf("%lld\n", cnt + 1);
    printf("1"); for (int i = 1; i <= cnt; i++) printf(" %lld", ans[i]);
    putchar('\n');
  }
  else {
    puts("0");
  }
  
}

signed main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }
  
  doit();
  print();
  return 0;
}