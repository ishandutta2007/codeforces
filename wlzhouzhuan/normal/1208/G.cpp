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

const int N = 1000005;

int n, k;

int phi[N], pr[N >> 3], len;
bool vis[N];
void xxs(int n) {
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) pr[++len] = i, phi[i] = i - 1;
    for (int j = 1; j <= len && pr[j] * i <= n; j++) {
      vis[pr[j] * i] = 1;
      if (i % pr[j] == 0) {
        phi[pr[j] * i] = phi[i] * pr[j];
        break;
      }
      phi[pr[j] * i] = phi[i] * (pr[j] - 1);
    }
  }
  phi[1] = phi[2] = 1e9;
}

int main() {
  n = read(), k = read();
  if (k == 1) return puts("3"), 0;
  xxs(n);
//  rep(i, 1, n) printf("phi[%d] = %d\n", i, phi[i]);
  nth_element(phi + 1, phi + k, phi + n + 1);
  ll ans = 2;
  rep(i, 1, k) ans += phi[i];
  print(ans, '\n');
  return 0;
}