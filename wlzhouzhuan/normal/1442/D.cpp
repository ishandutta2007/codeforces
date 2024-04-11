#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define fir first
#define sec second

namespace IO {
  const int SIZE = 1 << 20;
  char buf[SIZE], *p1 = buf, *p2 = buf;
  char obuf[SIZE], *O = obuf;
  int getc() {
    return getchar();
    //return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++;
  }
  int read() {
    int x = 0, f = 0;
    char ch = getc();
    while (!isdigit(ch)) f |= ch == '-', ch = getc();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getc();
    return f ? -x : x;
  }
  template<typename T> void print(T x) {
    if (x < 0) *O++ = '-', x = -x;
    if (x > 9) print(x / 10);
    *O++ = char(x % 10 + '0');
  }
  template<typename T> void print(T x, char opt) {
    print(x), *O++ = opt;
  } 
  void Flush() {
    fwrite(obuf, O - obuf, 1, stdout);
  }
}
using namespace IO;

const int N = 3005;
void ckmax(int &a, int b) {
  if (a < b) a = b;
}

vector<int> a[N];
ll sum[N];
int l[N], n, k;

vector<ll> solve(int l, int r) {
  if (l == r) {
    vector<ll> res(k + 1);
    for (int i = 1; i <= min(::l[l], k); i++) {
      res[i] = res[i - 1] + a[l][i];
    }
    return res;
  }
  int mid = l + r >> 1;
  vector<ll> L = solve(l, mid), R = solve(mid + 1, r);
  vector<ll> res(k + 1);
  for (int i = mid + 1; i <= r; i++) {
    int tot = min(::l[i], k);
    for (int j = k; j >= tot; j--)
      L[j] = max(L[j], L[j - tot] + sum[i]);
  }
  for (int i = l; i <= mid; i++) {
    int tot = min(::l[i], k);
    for (int j = k; j >= tot; j--)
      R[j] = max(R[j], R[j - tot] + sum[i]);
  }
  for (int i = 0; i <= k; i++) res[i] = max(L[i], R[i]);
  //printf("l = %d, r = %d, res = ", l, r);
  //for (int i = 1; i <= k; i++) printf("%d ", res[i]); puts("");
  return res;
}
int main() {
  n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    l[i] = read(), a[i].resize(l[i] + 1);
    for (int j = 1; j <= l[i]; j++) {
      a[i][j] = read();
      if (j <= k) sum[i] += a[i][j];
    } 
  }
  vector<ll> ans = solve(1, n);
  printf("%lld\n", ans[k]);
  return 0;
}