// Author: wlzhouzhuan
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

const int P = 998244353;
const int A[16] = {0, 0, 0, 24, 4, 240, 204, 1316, 2988, 6720, 26200, 50248, 174280, 436904, 1140888, 3436404};
const int F[16] = {P - 1, P - 4, P - 4, P - 16, 15, P - 44, 26, P - 48, P - 12, 4, P - 10, 16, P - 1, 8, 4, 0};
int tmp[31];

long long n;

void mul(int *a, int *b) {
  for (int i = 0; i < 31; i++) tmp[i] = 0;
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      tmp[i + j] = (tmp[i + j] + 1ll * a[i] * b[j]) % P;
    }
  }
  for (int i = 30; i >= 16; i--) {
    for (int j = 0; j <= 16; j++) {
      tmp[i - 16 + j] = (tmp[i - 16 + j] + 1ll * F[j] * tmp[i]) % P;
    }
  }
  for (int i = 0; i < 16; i++) a[i] = tmp[i]; 
}

int f[16], g[16];
void work() {
  scanf("%lld", &n);
  mset(f, 0), mset(g, 0);
  f[0] = g[1] = 1;
  while (n) {
    if (n & 1) mul(f, g);
    mul(g, g);
//    printf("now n = %lld\n", n);
//    for (int i = 0; i < 16; i++) printf("%d ", f[i]);
//    puts("");
//    for (int i = 0; i < 16; i++) printf("%d ", g[i]);
//    puts("");
    n >>= 1;
  }
  int ans = 0;
  for (int i = 0; i < 16; i++) ans = (ans + 1ll * f[i] * A[i]) % P;
  print(ans, '\n');
}

int main() {
  int T = 1;
  while (T--) work();
  return 0;  
}