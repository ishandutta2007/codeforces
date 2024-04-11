#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB 
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
using namespace std;
const int M = 1024 * 1024;

int T[M], dp[M], P[M];
int n, k;

bool check(int m)
{
  int ind = 0;
  for (int i = 0; i <= n; i++)
  {
    dp[i] = P[i] = 0;
  }
  dp[0] = P[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    while (T[i] - T[ind + 1] > m)
    {
      ind++;
    }
    if (ind <= i - k)
    {
      int lol = P[i - k];
      if (ind > 0)
      {
        lol -= P[ind - 1];
      }
      if (lol > 0)
      {
        dp[i] = 1;
      }

    }
      P[i] = P[i - 1] + dp[i];
  }
  return dp[n];
}

int main()
{
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", T + i);
  }
  sort(T + 1, T + n + 1);
  int st = 0, en = 1e9 + 1000000, mid = (st + en) / 2, res = en;
  while (st <= en)
  {
    if (check(mid))
    {
      res = min(res, mid);
      en = mid - 1;
    }
    else
    {
      st = mid + 1;
    }
    mid = (st + en) / 2;
  }
  printf("%d\n", res);
  return 0;
}