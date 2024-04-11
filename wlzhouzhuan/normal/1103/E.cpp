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

const int N = 400005;
const int lim = 100000;
const ull inv = 6723469279985657373ull;

struct num {
  ull a[5];
  num() { mset(a, 0); }
  ull calc() {
    return a[0] - a[2];
  }
} ans[N], omega[10], tmp[N], zero;

num operator + (num a, num b) {
  for (int i = 0; i < 5; i++) a.a[i] += b.a[i];
  return a;
}
num operator * (num a, num b) {
  static ull tmp[10]; mset(tmp, 0);
  num c;
  for (int i = 0; i < 5; i++) if (a.a[i])
    for (int j = 0; j < 5; j++)
      tmp[i + j] += a.a[i] * b.a[j];
  for (int i = 0; i < 5; i++)
    c.a[i] = tmp[i] - tmp[5 + i];
  return c;
}
num operator ^ (num a, int b) {
  num res; res.a[0] = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

void fwt(num *a, int opt) {
  for (int mid = 1; mid < lim; mid *= 10) {
    for (int i = 0; i < lim; i += 10 * mid) {
      for (int j = 0; j < mid; j++) {
        for (int k = 0; k < 10; k++) {
          tmp[i + k * mid + j] = a[i + k * mid + j];
          a[i + k * mid + j] = zero;
        }
        for (int k = 0; k < 10; k++) {
          for (int t = 0; t < 10; t++) {
            a[i + k * mid + j] = a[i + k * mid + j] + omega[(opt + 10) * k * t % 10] * tmp[i + t * mid + j];
          }
        }
      }
    }
  }
}

int n;

int main() {
  for (int i = 0; i < 10; i++) omega[i].a[i % 5] = (i >= 5 ? -1 : 1);
  n = read();
  for (int i = 1; i <= n; i++) {
    int x = read();
    ans[x].a[0]++;
  }
  fwt(ans, 1);
  
  for (int i = 0; i < lim; i++) ans[i] = ans[i] ^ n;
  
  fwt(ans, -1);
  
  for (int i = 0; i < n; i++) {
    print(((ans[i].calc() * inv) >> 5) % (1ull << 58), '\n');
  }
  return 0;
}

/*
20
1 1 4 5 1 4
1 9 1 9 8 1
0 1 1 4 5 1
4 5
*/