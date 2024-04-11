// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast") 
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

const int N = 5000005;
char a[N];
int Z[N], n, k;

int main() {
  scanf("%d%d%s", &n, &k, a + 1);
  for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];
  int pos = 0, r = 0;
  Z[1] = 2 * n;
  for (int i = 2; i <= 2 * n; i++) {
    if (i <= r) Z[i] = min(Z[i - pos + 1], r - i + 1);
    while (i + Z[i] <= 2 * n && a[i + Z[i]] == a[Z[i] + 1]) Z[i]++;
    if (i + Z[i] - 1 > r) pos = i, r = i + Z[i] - 1;
  }
  pos = n;
  for (int i = 2; i <= n; i++) {
    if (i + Z[i] <= 2 * n && a[i + Z[i]] > a[1 + Z[i]]) {
      pos = i - 1;
      break;
    } 
  }
//  cerr << "pos = " << pos << '\n';
  for (int i = 1; i <= k; i++) {
    putchar(a[(i - 1) % pos + 1]);
  }
  
}