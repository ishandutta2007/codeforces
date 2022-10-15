// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 5000005;
int cnt[N], a[N];
int n;

int visa[N], visb[N];
int ban[N];
void out(int x) {
  for (int i = 1; i <= n; i++) {
    if (!ban[i] && a[i] == x) {
      ban[i] = 1;
      printf("%d ", i);
      break;
    }
  }
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    cnt[a[i]]++;
  }
  for (int i = 1; i <= 2500000; i++) {
    if (cnt[i] >= 4) {
      puts("YES");
      out(i), out(i), out(i), out(i);
      return 0;
    }
  }
  int lst1 = 0, lst2 = 0;
  for (int i = 1; i <= 2500000; i++) {
    if (cnt[i] >= 2) {
      if (!lst1) lst1 = i;
      else lst2 = i;
    }
  }
  if (lst1 && lst2) {
    puts("YES");
    out(lst1), out(lst2), out(lst1), out(lst2);
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (!visa[a[i] + a[j]]) {
        visa[a[i] + a[j]] = i, visb[a[i] + a[j]] = j;
      } else if (visa[a[i] + a[j]] != i && visa[a[i] + a[j]] != j && visb[a[i] + a[j]] != i && visb[a[i] + a[j]] != j) {
        puts("YES");
        ban[i] = ban[j] = 1;
        printf("%d %d %d %d\n", i, j, visa[a[i] + a[j]], visb[a[i] + a[j]]);
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}