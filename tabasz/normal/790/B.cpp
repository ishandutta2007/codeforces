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
#define int LL
const int M=200005;

int n, k;
int dp[M][10];
LL res;
vector<int> V[M];

void DFS1(int v, int pre)
{
  dp[v][0]=1;
  REP(i, siz(V[v]))
  {
    if(V[v][i]!=pre)
    {
      DFS1(V[v][i], v);
      dp[v][k]+=dp[V[v][i]][k];
      dp[v][k]+=dp[V[v][i]][0];
      REP(j, k)
        dp[v][j]+=dp[V[v][i]][(j+k-1)%k];
    }
  }
  //printf("R[%d]=%d\n", v, dp[v][k]);
}

void DFS2(int v, int pre, vector<int> X)
{
  vector<int> Y=vector<int>(k+1, 0);
  res+=dp[v][k]+X[k]+X[0];
 // debug("%d: %d\n", v, dp[v][k]+X[k]+X[0]);
  REP(j, k)
    Y[j]+=X[(j+k-1)%k];
  Y[k]+=X[k]+X[0];
  REP(i, siz(V[v]))
  {
    if(V[v][i]!=pre)
    {
      Y[k]+=dp[V[v][i]][k]+dp[V[v][i]][0];
      REP(j, k)
        Y[j]+=dp[V[v][i]][(j+k-1)%k];
    }
  }
  Y[0]++;
  REP(i, siz(V[v]))
  {
    if(V[v][i]!=pre)
    {
      Y[k]-=dp[V[v][i]][k]+dp[V[v][i]][0];
      REP(j, k)
        Y[j]-=dp[V[v][i]][(j+k-1)%k];
      DFS2(V[v][i], v, Y);
      Y[k]+=dp[V[v][i]][k]+dp[V[v][i]][0];
      REP(j, k)
        Y[j]+=dp[V[v][i]][(j+k-1)%k];
    }
  }
}

main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%lld%lld", &n, &k);
  REP(i, n-1)
  {
    int a, b;
    scanf("%lld%lld", &a, &b);
    V[a].PB(b);
    V[b].PB(a);
  }
  DFS1(1, 0);
  DFS2(1, 0, vector<int>(k+1, 0));
  printf("%lld\n", res/2);
  return 0;
}