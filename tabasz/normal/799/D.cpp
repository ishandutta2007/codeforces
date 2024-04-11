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
const LL inf = 1e6;
const int M = 1e5+5;

LL dp[45][M];
vector<int> V;
int h, w, a, b, n;

bool cmp(int a, int b)
{
  return a > b;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d%d%d%d", &a, &b, &h, &w, &n);
  REP(i, n)
  {
    int x;
    scanf("%d", &x);
    V.PB(x);
  }
  sort(ALL(V), cmp);
  dp[0][1] = 1;
  RE(i, min(n, 40))
  {
    FORD(j, max(a, b), 1)
    {
      dp[i][j] = max(dp[i - 1][j] * V[i - 1], dp[i - 1][(j + V[i - 1] - 1) / V[i - 1]]);
      dp[i][j] = max(dp[i][j], dp[i][j + 1]);
     // debug("dp[%d][%d] = %d\n", i, j, dp[i][j]);
      if (dp[i][j] > inf)
      {
        dp[i][j] = inf;
      }
    }
  }
  int ha = (a + h - 1) / h;
  int wa = (a + w - 1) / w;
  int hb = (b + h - 1) / h;
  int wb = (b + w - 1) / w;
  bool boo = 0;
 // debug("%d %d %d %d\n", ha, hb, wa, wb);
  REP(i, min(40, n) + 1)
  {
    if (dp[i][ha] >= wb || dp[i][hb] >= wa)
    {
      boo = 1;
      printf("%d\n", i);
      break;
    }
  }
  if (!boo)
  {
    printf("-1\n");
  }
  return 0;
}