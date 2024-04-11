#include <bits/stdc++.h>
using namespace std;

int a[100005];
long long dp1[100005], dp2[100005];
int cnt[100005];

int main()
{
  int n, k;
  scanf("%d%d",&n,&k);
  for (int i = 1; i <= n; i++) scanf("%d",&a[i]);

  long long *d = dp1, *e = dp2;
  for (int i = 1; i <= n; i++) d[i] = 1e18;

  for (int i = 1; i <= k; i++, swap(d, e))
  {
    queue<tuple<int, int, int, int>> que;
    que.emplace(1, n, 1, n);

    int L = 1, R = 0;
    long long cost = 0;
    memset(cnt, 0, sizeof(cnt));

    while (que.empty() == false)
    {
      int l, r, lo, hi;
      tie(l, r, lo, hi) = que.front();
      
      int m = (l + r) / 2;
      que.pop();

      if (R > m)
      {
        L = 1; R = 0; memset(cnt, 0, sizeof(cnt)); cost = 0;
      }

      while (R < m) cost += cnt[a[++R]]++;
      while (L < lo) cost -= --cnt[a[L++]];
      while (L > lo) cost += cnt[a[--L]]++;

      int best = L;
      e[m] = cost + d[L - 1];

      while (L < min(m, hi))
      {
        cost -= --cnt[a[L++]];
        if (e[m] > cost + d[L - 1])
        {
          e[m] = cost + d[L - 1];
          best = L;
        }
      }

      if (l < m) que.emplace(l, m - 1, lo, best);
      if (m < r) que.emplace(m + 1, r, best, hi);
    }
  }

  printf("%lld\n", d[n]);
}