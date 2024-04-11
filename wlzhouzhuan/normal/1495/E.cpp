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

const int N = 5000005;
const int mod = 1e9 + 7;

int p[N], t[N], a[N], ans[N];
int n, m, k, seed, base;

int main() {
  n = read(), m = read();
  auto rnd = [&]() {
    int ret = seed;
    seed = (1ll * seed * base + 233) % mod;
    return ret;
  };
  for (int i = 1; i <= m; i++) {
    p[i] = read(), k = read(), seed = read(), base = read();
    for (int j = p[i - 1] + 1; j <= p[i]; j++) {
      t[j] = rnd() & 1;
      a[j] = rnd() % k + 1;
    }
  }
  if (t[1]) {
    for (int i = 1; i <= n; i++) t[i] ^= 1;
  }
  ll s0 = 0, s1 = 0;
  for (int i = 1; i <= n; i++) {
    if (t[i] == 0) s0 += a[i];
    else s1 += a[i]; 
  }
  
  //cerr << "ok! s0 = " << s0 << ", s1 = " << s1 << '\n';
  
  if (s0 <= s1) {
    for (int i = 1, j = 1; i <= n; i++) {
      if (!t[i]) {
        ans[i] = a[i];
        j = max(j, i);
        int res = a[i];
        while (res) {
          if (!t[(j - 1) % n + 1]) {
            j++;
            continue;
          }
          int zz = (j - 1) % n + 1;
          if (res <= a[zz] - ans[zz]) {
            ans[zz] += res;
            res = 0;
            break;
          } else {
            res -= a[zz] - ans[zz];
            ans[zz] = a[zz];
            j++; 
          }
        }
      }
    }
  } else {
    ans[1] = 1;
    for (int i = 1, j = 1; i <= n; i++) {
      if (t[i]) {
        ans[i] = a[i];
        j = max(j, i);
        int res = a[i];
        while (res) {
          if (t[(j - 1) % n + 1]) {
            j++;
            continue;
          }
          int zz = (j - 1) % n + 1;
          if (res <= a[zz] - ans[zz]) {
            ans[zz] += res;
            res = 0;
            break;
          } else {
            res -= a[zz] - ans[zz];
            ans[zz] = a[zz];
            j++; 
          }
        }
      }
    }
  }
  int ANS = 1;
  for (int i = 1; i <= n; i++) {
    ANS = 1ll * ANS * (((1ll * ans[i] ^ (1ll * i * i)) + 1) % mod) % mod;
  }
  printf("%d\n", ANS);
  return 0;
}