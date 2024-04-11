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
int a[N], cnt[N];
int n, m;

int f[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
bool check(int k) {
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= n; i++) {
    int b = (i - k + n) % n;
    if (!b) b = n;
    f[find(a[i])] = find(b);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) if (find(i) == i) cnt++;
  return n - cnt <= m;
}
void solve() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int k = 0; k < n; k++) cnt[k] = 0;
  for (int i = 1; i <= n; i++) cnt[(i - a[i] + n) % n]++;
  vector<int> ans;
  for (int k = 0; k < n; k++) {
    if (cnt[k] >= n - 2 * m) {
      if (check(k)) ans.pb(k);
    }
  }
  printf("%d ", SZ(ans));
  for (auto v: ans) printf("%d ", v); puts("");
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}