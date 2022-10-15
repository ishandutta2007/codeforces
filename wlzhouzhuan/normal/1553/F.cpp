#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, l, r) for (int i = l; i <= r; i++) 
#define per(i, l, r) for (int i = l; i >= r; i--)
#define pb push_back
#define SZ(x) (int(x.size()))

inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char ch) {
  print(x), putchar(ch);
}

template<typename T1, typename T2> void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

const int N = 300005;

// f[i] = f[i - 1] + \sum a[i] % a[j]
// g[i] = g[i - 1] + \sum a[j] % a[i]
ll f, g;
int n, x;

struct Fenwick {
  ll c[N];
  void add(int x, int dlt) {
    while (x < N)
      c[x] += dlt, x += x & -x;
  }
  ll qry(int x) {
    x = min(x, 300000);
    ll ret = 0;
    while (x)
      ret += c[x], x ^= x & -x;
    return ret; 
  }
  ll qry(int l, int r) {
    return qry(r) - qry(l - 1);
  }
} bit1, bit2, bit3;


int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int x = read();
    f += 1ll * (i - 1) * x + bit1.qry(x);
    ll lasts = 0; int lastc = 0;
    for (int j = 0; j <= 300000; j += x) {
      int cnt = bit3.qry(j + x - 1);
      ll sum = bit2.qry(j + x - 1);
      g += sum - lasts - 1ll * (cnt - lastc) * j;
      lasts = sum, lastc = cnt;
    }
    //printf("debug f = %lld, g = %lld\n", f, g);
    print(f + g, ' ');
    for (int j = x; j <= 300000; j += x) {
      bit1.add(j, -x);
    }
    bit2.add(x, x), bit3.add(x, 1);
  }
  puts("");
  return 0;
}