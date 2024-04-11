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

const int N = 1 << 19;
const int inf = 1e9;

int cnt[N];
int n, k;

struct Info {
  int val, maxx, minn, ans;
  void Set(int x) {
    val = 1;
    if (x) maxx = minn = 0, ans = inf;
    else maxx = -inf, minn = inf, ans = inf;
  }
}; 
Info merge(Info x, Info y) {
  Info z; 
  z.val = x.val + y.val;
  z.maxx = max(x.maxx, x.val + y.maxx);
  z.minn = min(x.minn, x.val + y.minn);
  z.ans = min(min(x.ans, y.ans), x.val + y.minn - x.maxx);
  return z;
}

vector<Info> tr[N << 2];

#define ls (u << 1)
#define rs (u << 1 | 1)
void build(int u, int l, int r) {
  int len = r - l + 1;
  tr[u].resize(len);
  if (l == r) {
    tr[u][0].Set(cnt[l]);
    return ;
  }
  int mid = l + r >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  int lef = mid - l + 1;
  for (int i = 0; i < lef; i++) {
    tr[u][i] = merge(tr[ls][i], tr[rs][i]);
    tr[u][lef + i] = merge(tr[rs][i], tr[ls][i]);
  }
}
 
int main() {
  n = read(), k = read();
  for (int i = 0; i < n; i++) {
    int x = read();
    cnt[x] = 1;
  }
  build(1, 0, (1 << k) - 1);
  for (int i = 0; i < (1 << k); i++) {
    print(tr[1][i].ans, ' ');
  }
  return 0;
}