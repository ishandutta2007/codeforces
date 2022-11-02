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
const int M = 1024 * 2;

int n, a, b;
double P[3][M];
pair<double, int> dp[M][M];

bool por(pair<double, int> a, pair<double, int> b)
{
  a.S *= -1;
  b.S *= -1;
  return a > b;
}

pair<double, int> check(double val)
{
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= a; j++)
    {
      dp[i][j] = MP(-1000000, 0);
    }
  }
  dp[0][0] = MP(0, 0);
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= a; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (j > 0)
      {
        if (por(MP(dp[i - 1][j - 1].F + P[0][i], dp[i - 1][j - 1].S), dp[i][j]))
        {
          dp[i][j] = MP(dp[i - 1][j - 1].F + P[0][i], dp[i - 1][j - 1].S);
        }
        if (por(MP(dp[i - 1][j - 1].F + P[2][i] - val, dp[i - 1][j - 1].S + 1), dp[i][j]))
        {
          dp[i][j] = MP(dp[i - 1][j - 1].F + P[2][i] - val, dp[i - 1][j - 1].S + 1);
        }
      }
      if (por(MP(dp[i - 1][j].F + P[1][i] - val, dp[i - 1][j].S + 1), dp[i][j]))
      {
        dp[i][j] = MP(dp[i - 1][j].F + P[1][i] - val, dp[i - 1][j].S + 1);
      }
    }
  }
  return dp[n][a];
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 0; i < 2; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      scanf("%lf", P[i] + j);
    }
  }
  for (int i = 1; i <= n; i++)
  {
    P[2][i] = P[0][i] + P[1][i] - P[0][i] * P[1][i];
  }
  double st = 0, en = 1000000.0;
  for (int i = 0; i < 60; i++)
  {
    double mid = (st + en) / 2.0;
    pair<double, int> res = check(mid);
    if (res.S >= b)
    {
      st = mid;
    }
    else
    {
      en = mid;
    }
  }
  printf("%.6lf\n", check(st).F + b * st);
  return 0;
}