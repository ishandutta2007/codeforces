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

const int N = 55;
int fi[3][3];
char a[N], b[N];
int n, t;

int main() {
  //  0  1  2 
  fi[0][0] = 0;
  fi[0][1] = -1;
  fi[0][2] = 1;
  fi[1][0] = 1;
  fi[1][1] = 0;
  fi[1][2] = -1;
  fi[2][0] = -1;
  fi[2][1] = 1;
  fi[2][2] = 0;

  scanf("%s%s", a, b);
  n = strlen(a);
  for (rint i = 0; i < n; i += 2) {
    int A, B;
    if (a[i] == '8') A = 0;
    if (a[i] == '(') A = 1;
    if (a[i] == '[') A = 2;
    if (b[i] == '8') B = 0;
    if (b[i] == '(') B = 1;
    if (b[i] == '[') B = 2;
    t += fi[A][B];
  } 
  puts(t == 0 ? "TIE" : t > 0 ? "TEAM 1 WINS" : "TEAM 2 WINS");
  return 0;
}