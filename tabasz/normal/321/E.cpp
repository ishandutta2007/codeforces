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
const int inf = 1e9;

int P[4 * M][4 * M];
int dp[M][4 * M];
int n, k;
//char* C;

int get(int l, int r)
{
  if (l > r)
  {
    return inf;
  }
  return P[r][r] - P[l - 1][r] - P[r][l - 1] + P[l - 1][l - 1];
}

void solve(int ind, int l, int r, int optl, int optr)
{
  if (l > r)
  {
    return;
  }
  int mid = (l + r) / 2;
  int optm = -1;
  dp[ind][mid] = inf;
  for (int i = optl; i <= min(optr, mid - 1); i++)
  {
    int r = get(i + 1, mid) + dp[ind - 1][i];
    if (dp[ind][mid] > r)
    {
      dp[ind][mid] = r;
      optm = i;
    }
  }
  solve(ind, l, mid - 1, optl, optm);
  solve(ind, mid + 1, r, optm, optr);
}

int nextInt()
{
  char c = getchar();
  while (c < '0' || c > '9')
  {
    c = getchar();
  }
  return c - '0';
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d %d\n", &n, &k);
  //C = (char *)malloc(8 * M);
  for (int i = 1; i <= n; i++)
  {
    //size_t len = 8 * M;
    //getline(&C, &len, stdin);
    //scanf("%s", C);
    for (int j = 1; j <= n; j++)
    {
      P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + nextInt();
    }
  }
  for (int i = 1; i <= n; i++)
  {
    dp[0][i] = inf;
  }
  for (int i = 1; i <= k; i++)
  {
    solve(i, 1, n, 0, n);
  }
  printf("%d\n", dp[k][n] / 2);
  return 0;
}