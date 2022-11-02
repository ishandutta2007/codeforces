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
const int M = 1024 * 256;
const double inf = 1e18;

int n, k;
double dp[55][M];
double D[M], PD[M], PR[M];
LL P[M];
int T[M];

void solve(int ind, int l, int r, int optl, int optr)
{
  if (l > r)
  {
    return;
  }
  int mid = (l + r) / 2, optm = -1;
  dp[ind][mid] = inf;
  for (int i = min(mid - 1, optr); i >= optl; i--)
  {
    double re = dp[ind - 1][i] + PR[mid] - PR[i] - (double)P[i] * (PD[mid] - PD[i]);
    if (dp[ind][mid] > re)
    {
      dp[ind][mid] = re;
      optm = i;
    }
  }
  //debug("%d %d %d %lf %d %d\n", ind, mid, optm, dp[ind][mid], optl, optr);
  solve(ind, l, mid - 1, optl, optm);
  solve(ind, mid + 1, r, optm, optr);
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
  {
    int a;
    scanf("%d", &a);
    T[i] = a;
    D[i] = 1.0 / (double)a;
    P[i] = P[i - 1] + T[i];
    PD[i] = D[i] + PD[i - 1];
    PR[i] = PR[i - 1] + (double)P[i] * D[i];
  }
  for (int i = 1; i <= n; i++)
  {
    dp[0][i] = inf;
  }
  for (int i = 1; i <= k; i++)
  {
    solve(i, 1, n, 0, n);    
  }
  printf("%.8lf\n", dp[k][n]);
  return 0;
}