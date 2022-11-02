#include<bits/stdc++.h>
using namespace std;
# ifdef DEB
# define debug(...) fprintf(stderr, __VA_ARGS__)
# else
# define debug(...)
#endif
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
#define VI vector<int>
#define VPI vector<PII>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define ALL(x) (x).begin(), (x).end()
#define siz(V) ((int)V.size())
const int M = 1024;

int n, m;
int V[M];
int res = 1000, r = 0;
int P[M];

int dp1[(1<<22)], dp2[(1<<22)];

int main()
{
  //ios_base::sync_with_stdio(0);
  P[0] = 1;
  for (int i = 1; i < 30; i++)
  {
    P[i] = P[i - 1] * 2;
  }
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    V[i] |= P[i];
  }
  for (int i = 0; i < m; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    V[a] |= (1<<b);
    V[b] |= (1<<a);
  }
  if (m == (n * (n - 1)) / 2)
  {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i < P[n]; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if ((i>>j) % 2)
      {
        dp2[i] = dp2[i ^ P[j]] | V[j];
        break;
      }
    }
    if (__builtin_popcount(i) == 1)
    {
      dp1[i] = true;
    }
    else
    {
      for (int j = 0; j < n; j++)
      {
        if ((i>>j) % 2 && dp1[i ^ P[j]])
        {
          if ((V[j] & i) != P[j])
          {
            if (i == 5)
            {
             // debug("   %d %d %d %d %d %d\n", j, i ^ P[j], V[j], i, V[j] & i, P[j]);
            }
            dp1[i] = true;
            break;
          }
        }
      }
    }
   // debug("%d %d %d\n", i, dp1[i], dp2[i]);
    if (dp1[i] && __builtin_popcount(dp2[i] | i) == n)
    {
      if (res > __builtin_popcount(i))
      {
        res = __builtin_popcount(i);
        r = i;
      }
    }
  }
  printf("%d\n", res);
  for (int i = 0; i < n; i++)
  {
    if ((r>>i) % 2 == 1)
    {
      printf("%d ", i + 1);
    }
  }
  printf("\n");
  return 0;
}