#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 6e5 + 1;

int n, m;
int h = sizeof(int) * 8 - __builtin_clz(MAXN);
int d[2 * MAXN];
int t[2 * MAXN];
void apply(int p, int value) {
  t[p] += value;
  if (p < m) d[p] += value;
}

void build(int p) {
  while (p > 1) p >>= 1, t[p] = min(t[p<<1], t[p<<1|1]) + d[p];
}

void push(int p) {
  for (int s = h; s > 0; --s) {
    int i = p >> s;
    if (d[i] != 0) {
      apply(i<<1, d[i]);
      apply(i<<1|1, d[i]);
      d[i] = 0;
    }
  }
}

void inc(int l, int r, int value) {
  l += m, r += m;
  int l0 = l, r0 = r;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) apply(l++, value);
    if (r&1) apply(--r, value);
  }
  build(l0);
  build(r0 - 1);
}

int query(int l, int r) {
  l += m, r += m;
  push(l);
  push(r - 1);
  int res = inf;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res, t[l++]);
    if (r&1) res = min(t[--r], res);
  }
  return res;
}

struct Interval{
    int l, r, w;
    bool operator<(const Interval &rhs) const{
        return w < rhs.w;
    }
} a[MAXN];

bool check(int x){
    ms(t, 0);
    ms(d, 0);
    int p = 1;
    for (int i = 1; i <= n; ++i){
        inc(a[i].l - 1, a[i].r - 1, 1);
        while (a[p].w < a[i].w - x){
            inc(a[p].l - 1, a[p].r - 1, -1);
            p++;
        }
        // for (int i = 0; i <= m - 2; ++ i) cout << query(i, i+1) << " ";
        // cout << '\n';
        // cout << query(0, m - 1) << '\n';
        if (query(0, m - 1) > 0) return 1;
    }
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;

    vector<int> cmp = {0};
    for (int i = 1; i <= n; ++i){
        cin >> a[i].l >> a[i].r >> a[i].w;
        cmp.push_back(a[i].l);
        cmp.push_back(a[i].r);
    }
    sort(cmp.begin(), cmp.end());
    cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
    m = cmp.size() - 1;
    for (int i = 1; i <= n; ++i){
        a[i].l = lower_bound(cmp.begin(), cmp.end(), a[i].l) - cmp.begin();
        a[i].r = lower_bound(cmp.begin(), cmp.end(), a[i].r) - cmp.begin();
    }
    sort(a + 1, a + 1 + n);
    // check(3);
    int lo = 0, hi = 1e6, mi;
    while (lo < hi){
        mi = (lo + hi) >> 1;
        if (check(mi)) hi = mi;
        else lo = mi + 1;
    }
    cout << lo << '\n';
}