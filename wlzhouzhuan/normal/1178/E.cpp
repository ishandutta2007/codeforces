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

const int N = 1000005;
char s[N];
char ans[N];
int n, len;
char ext = ' ';

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  if (n <= 3) {
    printf("%c\n", s[1]);
    return 0;
  }
   
  for (int i1 = 1, i2 = 2, j1 = n - 1, j2 = n; i2 < j1; i1 += 2, i2 += 2, j1 -= 2, j2 -= 2) {
    if (s[i1] == s[j1]) ans[len++] = s[i1];
    else if (s[i1] == s[j2]) ans[len++] = s[i1];
    else if (s[i2] == s[j1]) ans[len++] = s[i2];
    else if (s[i2] == s[j2]) ans[len++] = s[i2];
  }
  if (n % 4 >= 2) {
    ext = s[n / 2];
  }
  
  for (int i = 0; i < len; i++) printf("%c", ans[i]);
  if (ext != ' ') printf("%c", ext);
  for (int i = len - 1; i >= 0; i--) printf("%c", ans[i]);
  return 0;
}