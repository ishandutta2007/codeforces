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
const int M = 1024 * 128;
const LL inf = 1e18;

int n, m, p;
LL dp[128][M], pre[M], P[M];
vector<int> V;

void solve(int ind, int l, int r, int optl, int optr)
{
  if (l > r)
  {
    return;
  }
  int mid = (l + r) / 2;
  dp[ind][mid] = inf;
  int optm = -1;
  LL sum = pre[optl  + 1] - pre[mid] - (LL)(mid - optl - 1) * (V[m - 1] - V[mid - 1]);
  for (int i = optl; i <= min(optr, mid - 1); i++)
  {
    LL r = dp[ind - 1][i] + sum;
    if (dp[ind][mid] > r)
    {
      dp[ind][mid] = r;
      optm = i;
    }
    sum -= V[mid - 1] - V[i];
  }
  //debug("  %d %d: %d %d: %lld\n", l, r, mid, optm, dp[ind][mid]);
  solve(ind, l, mid - 1, optl, optm);
  solve(ind, mid + 1, r, optm, optr);
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 2; i <= n; i++)
  {
    int a;
    scanf("%d", &a);
    P[i] = P[i - 1] + a;
  }
  for (int i = 0; i < m; i++)
  {
    int h, t;
    scanf("%d%d", &h, &t);
    V.PB(t - P[h]);
  }
  sort(ALL(V));
  for (int i = m - 1; i > 0; i--)
  {
    pre[i] = pre[i + 1] + V[m - 1] - V[i - 1];
  }
  for (int i = 0; i < m; i++)
  {
  //  debug("%d ", V[i]);
  }
  //debug("\n");
  for (int i = 1; i <= m; i++)
  {
  //  debug("%d ", pre[i]);
  }
  //debug("\n");
  LL sum = 0, time = V[0];
  for (int i = 2; i <= m; i++)
  {
    LL dt = V[i - 1] - time;
    sum += dt * (i - 1);
    time += dt;
    sum += time - V[i - 1];
    dp[1][i] = sum;
    //debug("%lld ", dp[1][i]);
  }
  //debug("\n");
  for (int i = 2; i <= p; i++)
  {
    solve(i, 1, m, 0, m);
  }
  printf("%lld\n", dp[p][m]);
  return 0;
}