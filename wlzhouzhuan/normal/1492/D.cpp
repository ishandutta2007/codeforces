// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
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

#define N 1111111
int A[N], B[N], x, y;

int main() {
  int a = read(), b = read(), k = read();
  if (a == 0) {
    if (k) {
      puts("No");
    } else {
      puts("Yes");
      for (int i = 1; i <= b; i++) printf("1"); puts("");
      for (int i = 1; i <= b; i++) printf("1"); puts("");
    }
    return 0;
  }
  b--;
  if (b == 0) {
    if (k) {
      puts("No");
      return 0;
    }
    puts("Yes");
    for (int i = 1; i <= a + b + 1; i++) {
      if (i == 1) printf("1");
      else printf("0");
    }
    puts("");
    for (int i = 1; i <= a + b + 1; i++) {
      if (i == 1) printf("1");
      else printf("0");
    }
    puts("");
    return 0;
  }
  if (a + b - 1 < k) {
    puts("No");
    return 0;
  }
  puts("Yes");
  if (k == 0) {
    printf("11");
    for (int i = 1; i <= a; i++) printf("0");
    for (int i = 1; i <= b - 1; i++) printf("1");
    puts("");
    printf("11");
    for (int i = 1; i <= a; i++) printf("0");
    for (int i = 1; i <= b - 1; i++) printf("1");
    puts("");
    return 0; 
  }
  A[1] = 1, A[2] = 1;
  x = a, y = b - 1;
  A[2 + k] = 0, x--;
  for (int i = 3 + k; i <= a + b + 1; i++) {
    if (y) A[i] = 1, y--;
    else A[i] = 0, x--;
  }
  for (int i = 3; i <= k + 1; i++) {
    if (y) A[i] = 1, y--;
    else A[i] = 0, x--;
  }
  B[1] = 1, B[2] = 0;
  x = a - 1, y = b;
  B[2 + k] = 1, y--;
  for (int i = 3 + k; i <= a + b + 1; i++) {
    if (y) B[i] = 1, y--;
    else B[i] = 0, x--;
  }
  for (int i = 3; i <= k + 1; i++) {
    if (y) B[i] = 1, y--;
    else B[i] = 0, x--;
  }
  assert(x == 0 && y == 0);
  for (int i = 1; i <= a + b + 1; i++) printf("%d", A[i]); puts("");
  for (int i = 1; i <= a + b + 1; i++) printf("%d", B[i]); puts("");
  return 0;
} 
// k-1 + a+b-k-1 =a+b-2