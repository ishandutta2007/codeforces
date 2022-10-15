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

int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
void print(int x) {
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    char s[5];
    scanf("%s", s);
    int n = strlen(s);
    int cnt = 0;
    for (int i = 0; i < n; i++) if (s[i] != '0') cnt++;
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') continue;
      printf("%c", s[i]);
      for (int j = i + 1; j < n; j++) {
        printf("0");
      }
      printf(" ");
    }
    puts("");
  }
}