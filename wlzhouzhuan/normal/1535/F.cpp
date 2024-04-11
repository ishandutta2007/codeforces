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

const int N = 500005;
const int mod = 998244353;
int lg[N];

int base1 = 117, base2 = 137;
struct node {
  pii hsh;
  int id;
} a[N];
ll ans;
string s[N], t[N];
int n;

pii getHash(string s) {
  static int cnt[26]; mset(cnt, 0);
  int res1 = 0, res2 = 0;
  for (auto v: s) cnt[v - 'a']++;
  for (int i = 0; i < 26; i++) {
    res1 = (1ll * res1 * base1 + cnt[i] + 1) % mod;
    res2 = (1ll * res2 * base2 + cnt[i] + 1) % mod;
  }
  return make_pair(res1, res2);
}

struct SA {
  int cnt[N], x[N], y[N], sa[N], rk[N];
  char _a[N];
  int _n;
  void mysort(int m) {
    m = max(m, 255);
    for (int i = 1; i <= m; i++) cnt[i] = 0;
    for (int i = 1; i <= _n; i++) cnt[x[i]]++;
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = _n; i >= 1; i--) sa[cnt[x[y[i]]]--] = y[i];
  }
  void build(char a[], int n) {
    _n = n;
    for (int i = 1; i <= _n; i++) _a[i] = a[i];
    for (int i = 1; i <= _n; i++) x[i] = a[i], y[i] = i;
    mysort(n);
    for (int k = 1; k <= n; k <<= 1) {
      int cur = 0, p;
      for (int i = n - k + 1; i <= _n; i++) y[++cur] = i;
      for (int i = 1; i <= _n; i++) if (sa[i] > k) y[++cur] = sa[i] - k;
      mysort(n);
      for (int i = 1; i <= _n; i++) swap(x[i], y[i]);
      x[sa[1]] = 1, p = 1;
      for (int i = 2; i <= _n; i++) {
        x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p : ++p);
      }
      if (p == _n) break;
    }
    memcpy(rk, x, 4 * (_n + 1));
  }
  int height[N], LCP[N][18];
  void getHeight(int n) {
    for (int i = 1, k = 0; i <= n; i++) {
      if (rk[i] == 1) continue;
      if (k) --k;
      int j = sa[rk[i] - 1];
      while (i + k <= n && j + k <= n && _a[i + k] == _a[j + k]) k++;
      height[rk[i]] = k;
    }
    for (int i = 1; i <= n; i++) LCP[i][0] = height[i];
    for (int j = 1; j <= lg[n]; j++) {
      for (int i = 1; i + (1 << j) - 1 <= n; i++) {
        LCP[i][j] = min(LCP[i][j - 1], LCP[i + (1 << j - 1)][j - 1]);
      }
    }
  }
  int lcp(int x, int y) {
    if (x == y) return _n - x + 1;
    x = rk[x], y = rk[y];
    if (x > y) swap(x, y);
    x++;
    int len = lg[y - x];
    return min(LCP[x][len], LCP[y - (1 << len) + 1][len]);
  }
  // addition
  pii range(int x, int k) {
    x = rk[x];
    int l = x, r = x;
    for (int i = lg[l - 1]; i >= 0; i--) {
      if (l - (1 << i) >= 1 && LCP[l - (1 << i) + 1][i] >= k) l -= 1 << i;
    }
    for (int i = lg[_n - r]; i >= 0; i--) {
      if (r + (1 << i) <= _n && LCP[r + 1][i] >= k) r += 1 << i;
    }
    return make_pair(l, r);
  } 
} pre, suf;

struct Count {
  int n;
  struct Fenwick {
    int c[N], _n;
    void clear(int n) {
      _n = n;
      memset(c, 0, 4 * (n + 1));
    }
    void add(int x, int dlt) {
//      printf("add %d %d\n", x, dlt);
      while (x <= _n) c[x] += dlt, x += x & -x;
//      printf("!\n");
    }
    int qry(int x) {
      int ret = 0;
//      printf("qry %d\n", x);
      while (x > 0) ret += c[x], x ^= x & -x;
//      printf("!\n");
      return ret;
    }
    int qry(int l, int r) {
      if (l > r) return 0;
      else return qry(r) - qry(l - 1);
    }
  } bit;
  vector<int> dot[N];
  struct Item { int l, r, opt; };
  vector<Item> qry[N];
  void clear(int _n) {
    n = _n;
    bit.clear(n);
    for (int i = 0; i <= n; i++) dot[i].clear(), qry[i].clear();
  }
  void pushdot(int x, int y) {
//    printf("pushdot %d %d\n", x, y);
    dot[x].pb(y);
  }
  void pushqry(int xl, int xr, int yl, int yr) {
//    printf("pushqry %d %d %d %d\n", xl, xr, yl, yr);
    qry[xl - 1].pb({yl, yr, -1});
    qry[xr].pb({yl, yr, 1});
  }
  ll getans() {
    ll res = 0;
    for (int i = 1; i <= n; i++) {
      for (auto v: dot[i]) bit.add(v, 1);
      for (auto v: qry[i]) res += v.opt * bit.qry(v.l, v.r);
    }
    return res;
  }
} counter;

char prea[N], sufa[N];
int bga[N], bgb[N];

void solve(string a[], int n) {
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    bga[i] = tot + 1;
    for (int j = 0; j < SZ(a[i]); j++) prea[++tot] = a[i][j];
  }
  prea[tot + 1] = 0;
  tot = 0;
  for (int i = 1; i <= n; i++) {
    bgb[i] = tot + 1;
    for (int j = SZ(a[i]) - 1; j >= 0; j--) sufa[++tot] = a[i][j];
  }
  sufa[tot + 1] = 0;
  pre.build(prea, tot), pre.getHeight(tot);
  suf.build(sufa, tot), suf.getHeight(tot);
//  cerr << "!\n";
//  printf("tot = %d\n", tot);
//  for (int i = 1; i <= tot; i++) printf("%c", prea[i]); puts("");
//  for (int i = 1; i <= tot; i++) printf("rk[%d] = %d\n", i, pre.rk[i]);
  
  counter.clear(tot);
  for (int i = 1; i <= n; i++) counter.pushdot(pre.rk[bga[i]], suf.rk[bgb[i]]);
//  cerr << "!!!\n";
  
  ll res = 0;
  for (int i = 1; i <= n; i++) {
    for (int l = 0, r = 0; l < SZ(a[i]); l = r) {
      r = l + 1;
      while (r < SZ(a[i]) && a[i][r - 1] <= a[i][r]) r++;
//      printf("l = %d, r = %d\n", l, r);
      res--;
      pii rngL = pre.range(bga[i], l);
      pii rngR = suf.range(bgb[i], SZ(a[i]) - r);
//      printf("??? %d %d %d %d\n", rngL.fir, rngL.sec, rngR.fir, rngR.sec);
      counter.pushqry(rngL.fir, rngL.sec, rngR.fir, rngR.sec);
    }
  }
//  cerr << "!\n";
  res += counter.getans();
//  cerr << "?\n";
//  printf("res = %lld\n", res);
  ans += res + 2ll * (1ll * n * (n - 1) / 2 - res);
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  lg[1] = 0;
  for (int i = 2; i < N; i++) lg[i] = lg[i >> 1] + 1; 
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    a[i] = {getHash(s[i]), i};
  }
  sort(a + 1, a + n + 1, [&](node x, node y) {
    return x.hsh < y.hsh;
  });
  for (int i = 1; i <= n; i++) t[i] = s[a[i].id];
  for (int i = 1, j = 1; i <= n; i = j) {
    while (a[i].hsh == a[j].hsh) j++;
//    cerr << "i = " << i << ", j = " << j << '\n';
    ans += 1337ll * (j - i) * (i - 1);
    solve(t + i - 1, j - i);
  }
  cout << ans << '\n';
  return 0;
}