// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)

template <typename T>
void ckmax(T &a, T b) {
  if (a < b) a = b;
}
template <typename T>
void ckmin(T &a, T b) {
  if (a > b) a = b;
}
inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

const ll mod = 1000000007;
const ll inv2 = 500000004;
const int N = 700005;

long long qpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
ll pw[N], inv[N];
int a[N], pos[N], v[N], n, q;
// pair <int, int>  <id> 
pair <int, int> tmp[N << 1];
int tot;

struct SegmentTree {
  #define ls (u << 1)
  #define rs (u << 1 | 1)
  /*
  lval[u]  a[i] * 2^{i-1}
  rval[u]  a[i] / 2^i 
  val[u]  sum{a[i] * 2^{i-1} * a[j] / 2^j}
  count[u]  
  */
  ll val[N << 2], lval[N << 2], rval[N << 2];
  ll count[N << 2];
  void pushup(int u) {
    val[u] = (val[ls] + val[rs] + lval[ls] * rval[rs] % mod * inv[count[ls]]) % mod;
    lval[u] = (lval[ls] + lval[rs] * pw[count[ls]]) % mod;
    rval[u] = (rval[ls] + rval[rs] * inv[count[ls]]) % mod;
    count[u] = count[ls] + count[rs];
    return ;
  }
  void update(int u, int l, int r, int pos, int opt) {
    if (l > r || pos < l || pos > r) return ;
    if (l == r) {
      if (opt == 1) { //  
        val[u] = 0;
        lval[u] = tmp[pos].first;
        rval[u] = tmp[pos].first * inv2 % mod;
        count[u] = 1;  
      } else { // 
        val[u] = 0;
        lval[u] = 0;
        rval[u] = 0;
        count[u] = 0;
      }
      return ;
    }
    int mid = l + r >> 1;
    if (pos <= mid) update(ls, l, mid, pos, opt);
    else update(rs, mid + 1, r, pos, opt);
    pushup(u);
  }
  void getans() {
    printf("%lld\n", val[1]);
  }
} smt;

int main() {
  scanf("%d", &n);
  pw[0] = inv[0] = 1;
  for (rint i = 1; i <= (n << 1); i++) {
    pw[i] = pw[i - 1] * 2 % mod;
    inv[i] = inv[i - 1] * inv2 % mod;
  }
  for (rint i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    tmp[++tot] = make_pair(a[i], i);
  }
  scanf("%d", &q);
  for (rint i = 1; i <= q; i++) {
    scanf("%d%d", &pos[i], &v[i]);
    tmp[++tot] = make_pair(v[i], n + i);
  }
  sort(tmp + 1, tmp + tot + 1); // pair 
  //tot = unique(tmp + 1, tmp + tot + 1) - (tmp + 1);

  for (rint i = 1; i <= n; i++) a[i] = lower_bound(tmp + 1, tmp + tot + 1, make_pair(a[i], i)) - tmp;
  for (rint i = 1; i <= q; i++) v[i] = lower_bound(tmp + 1, tmp + tot + 1, make_pair(v[i], n + i)) - tmp;
  for (rint i = 1; i <= n; i++) smt.update(1, 1, tot, a[i], 1);
  
  smt.getans();
  for (rint i = 1; i <= q; i++) {
    smt.update(1, 1, tot, a[pos[i]], -1);
    a[pos[i]] = v[i];
    smt.update(1, 1, tot, a[pos[i]], 1);
    smt.getans();
  }
  return 0;
}