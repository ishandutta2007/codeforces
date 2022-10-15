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

ll n, k;

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    if (k > n) {
      puts("NO"); continue;
    }
    if (n & 1) {
      if (k & 1) {
        puts("YES");
        for (int i = 1; i < k; i++) {
          printf("1 ");
        }
        printf("%d\n", n - (k - 1));
      } else {
        puts("NO"); continue;
      }
    } else {
      if (n >= 2 * k) {
        
        puts("YES");
        for (int i = 1; i < k; i++) {
          printf("2 ");
        }
        printf("%d\n", n - 2 * (k - 1));
      } else {
        if (k & 1) {
          puts("NO"); continue;
        } else { 
          puts("YES");
          for (int i = 1; i < k; i++) {
            printf("1 ");
          }
          printf("%d\n", n - (k - 1));
        }
      }
    }
  } 
  return 0;
}