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
const int mod=1e9+7;

int B[5005][30], boo[30];
int dp[5005][5005];
int n;
char C[5005];

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%s", &n, C);
  RE(i, n)
    REP(j, 26)
      B[i][j]=-1;
  RE(i, n)
  {
    for(int j=i-1; j>0; j--)
    {
      int lol=(int)C[j-1]-(int)'a';
      if(C[j-1]!=C[i-1] && B[i][lol]==-1)
        B[i][lol]=j;
    }
  }
  RE(i, n)
  {
    RE(j, n)
    {
      dp[i][j]=1;
      if(i==1)
        continue;
      dp[i][j]+=dp[i-1][j];
      if(dp[i][j]>=mod)
        dp[i][j]-=mod;
      if(j==1)
      {
        //debug("%d %d: %d\n", i, j, dp[i][j]);
        continue;
      }
      //debug("           %d %d: %d\n", i, j, dp[i][j]);
      if(C[j-1]==C[j-2])
        dp[i][j]=dp[i][j-1];
      else
      {
        dp[i][j]--;
        dp[i][j]+=dp[i][j-1];
        if(dp[i][j]>=mod)
          dp[i][j]-=mod;
        //dp[i][j]-=dp[i-1][j-1];
       //if(dp[i][j]<0)
        //  dp[i][j]+=mod;
        if(B[j-1][(int)C[j-1]-(int)'a']!=-1)
        {
          dp[i][j]-=dp[i-1][B[j-1][(int)C[j-1]-(int)'a']];
          if(dp[i][j]<0)
            dp[i][j]+=mod;
          //dp[i][j]+=dp[i-2][B[j-1][(int)C[j-1]-(int)'a']];
          //if(dp[i][j]>=mod)
           // dp[i][j]-=mod;
        }
      }
      //debug("%d %d: %d\n", i, j, dp[i][j]);
      /*REP(k, siz(V[j]))
      {
       // debug("%d %d: %d\n", i, j, V[j][k]);
        dp[i][j]+=dp[i-1][V[j][k]];
        if(dp[i][j]>=mod)
          dp[i][j]-=mod;
      }*/
    }
  }
  /////////////////////////////////////////////////////////////////
  int res=0;
  for(int i=n; i>0; i--)
  {
    if(boo[(int)C[i-1]-(int)'a'])
      continue;
    boo[(int)C[i-1]-(int)'a']=1;
    res+=dp[n][i];
    if(res>=mod)
      res-=mod;
    res-=dp[n-1][i];
    if(res<0)
      res+=mod;
  }
  printf("%d\n", res);
  return 0;
}