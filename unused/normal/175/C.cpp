#include <bits/stdc++.h>
using namespace std;

map<int, long long> mp;
long long p[105];

int main()
{
  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++)
  {
    int k, c;
    scanf("%d%d",&k,&c);
    mp[c] += k;
  }

  int t;
  scanf("%d",&t);
  for (int i = 1; i <= t; i++) scanf("%lld", &p[i]);
  for (int i = t; i >= 1; i--) p[i] -= p[i - 1];
  p[t + 1] = 1e18;

  long long ans = 0;
  int X = 1;
  while (mp.empty() == false)
  {
    if (mp.begin()->second < p[X])
    {
      ans += X * mp.begin()->second * mp.begin()->first;
      p[X] -= mp.begin()->second;
      mp.erase(mp.begin());
    }
    else if (mp.begin()->second > p[X])
    {
      ans += X * p[X] * mp.begin()->first;
      mp.begin()->second -= p[X];
      ++X;
    }
    else
    {
      ans += X * mp.begin()->second * mp.begin()->first;
      mp.erase(mp.begin());
      ++X;
    }
  }

  printf("%lld\n", ans);
}