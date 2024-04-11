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
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { a > b && a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { a < b && a = b; }
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

const int N = 200005;
vector<int> vec[N];
int lg[N];
int a[N], b[N], rmq[N][18], rmq2[N][18], n;
int RMQ(int l, int r) {
  int len = lg[r - l + 1];
  return max(rmq[l][len], rmq[r - (1 << len) + 1][len]);
}
int RMQ2(int l, int r) {
  int len = lg[r - l + 1];
  return min(rmq2[l][len], rmq2[r - (1 << len) + 1][len]);
}
void solve() {
  n = read();
  rep(i, 1, n) a[i] = read(), b[i] = a[i], vec[i].clear();
  sort(b + 1, b + n + 1);
  rep(i, 1, n) {
    a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
    vec[a[i]].push_back(i);
    rmq[i][0] = a[i];
    rmq2[i][0] = a[i];
  }
  rep(j, 1, 17) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << j - 1)][j - 1]);
      rmq2[i][j] = min(rmq2[i][j - 1], rmq2[i + (1 << j - 1)][j - 1]);
    }
  }
  rep(i, 1, n - 2) {
    int x = RMQ(1, i), tail = n;
    per(j, 17, 0) {
      if (tail >= (1 << j) && RMQ(tail - (1 << j) + 1, tail) <= x)
        tail -= 1 << j;
    }
    int id = lower_bound(vec[x].begin(), vec[x].end(), i + 1) - vec[x].begin();
    if (id == vec[x].size()) continue;
    id = max(vec[x][id], tail);
    if (id != n && RMQ2(i + 1, id) == x && RMQ(id + 1, n) == x) {
      printf("YES\n%d %d %d\n", i, id - i, n - id);
      return ;
    }
  }
  puts("NO");
}
int main() {
  lg[1] = 0;
  rep(i, 2, N - 1) lg[i] = lg[i >> 1] + 1;
  int T = read();
  while (T--) solve();
  return 0;
}