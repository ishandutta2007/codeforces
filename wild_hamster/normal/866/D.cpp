#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 550
//#define N 1000005
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx;
ll a[300500];
ll t[600500], d[600500];

void apply(int p, int value) {
  t[p] += value;
  if (p < n) d[p] += value;
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
  l += n, r += n;
  int l0 = l, r0 = r;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) apply(l++, value);
    if (r&1) apply(--r, value);
  }
  build(l0);
  build(r0 - 1);
}

int query(int l, int r) {
  l += n, r += n;
  push(l);
  push(r - 1);
  int res = 2e9;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res, t[l++]);
    if (r&1) res = min(t[--r], res);
  }
  return res;
}
vector<pii> f;

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        f.push_back(mp(a[i], i));
    }
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());
    for (i = 0; i < n; i++)
        inc(i, i+1, i+1);
    //for (i = 0; i < n; i++)
    long long ans = 0;
    for (i = 0; i < n; i++)
    {
        ll pos = f[i].Y;
        ll val = f[i].X;
        inc(pos, n, -2);
        ll res = query(0, n);
        if (res >= 0)
        {
            ans += val;
        } else
        {
            inc(pos, n, 1);
            res = query(0, n);
            if (res < 0)
            {
                inc(pos, n, 1);
                ans -= val;
            }
        }
    }
    cout << ans << endl;
    return 0;
}