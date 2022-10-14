#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,w,path_w,m,a[100500],used[100500], t[100500];
ll dp[100500][52], d[100500];
int h = 16;

void apply(int p, int value) {
  t[p] += value;
  if (p < n) d[p] += value;
}

void build(int p) {
  while (p > 1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
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
  int res = -2e9;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]);
    if (r&1) res = max(t[--r], res);
  }
  return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> a[i];
    dp[0][0] = 0;
    for (i = 0; i < n; i++)
        if (!used[a[i]])
            dp[i+1][1] = dp[i][1]+1, used[a[i]] = 1;
        else
            dp[i+1][1] = dp[i][1];
    for (j = 1; j < k; j++)
    {
        for (i = 0; i < 2*n; i++)
            d[i] = t[i] = 0;
        for (i = n; i < 2*n; i++)
        {
            t[i] = dp[i-n][j];
            build(i);
        }
        for (i = 1; i <= n; i++)
            used[i] = -1;
        for (i = 0; i < n; i++)
        {
            inc(used[a[i]]+1, i+1, 1);
            used[a[i]] = i;
            dp[i+1][j+1] = query(0,i+1);
        }
        //for (i = 0; i < n; i++)
        //    cout << query(i,i+1) << " ";
    }
    cout << dp[n][k] << endl;
    return 0;
}