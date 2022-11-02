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
const int M=80;
const int inf=1e9;

int n, v, k, r;
char C[M];
int close[M][3];//0-K; 1-V; 2-rest
int dp[M][M][M][4];//last: 0-K,1-V,2-rest,3-all

int get(int ii, int kk, int vv, int rr)
{
  int res=0;
  for(int i=0; i<n; i++)
  {
    if(C[i]=='K')
    {
      if(kk==0)
      {
        if(ii==0)
          return res;
        else
          res++;
      }
      else
        kk--;
    }
    else
    {
      if(C[i]=='V')
      {
        if(vv==0)
        {
          if(ii==1)
            return res;
          else
            res++;
        }
        else
          vv--;
      }
      else
      {
        if(rr==0)
        {
          if(ii==2)
            return res;
          else
            res++;
        }
        else
          rr--;
      }
    }
  }
}

main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%s", &n, C);
  for(int i=0; i<n; i++)
  {
    if(C[i]=='V')
      v++;
    if(C[i]=='K')
      k++;
    for(int j=0; j<3; j++)
      close[i][j]=-1;
    for(int j=n-1; j>=i; j--)
    {
      if(C[j]=='K')
        close[i][0]=j-i;
      if(C[j]=='V')
        close[i][1]=j-i;
      if(C[j]!='K' && C[j]!='V')
        close[i][2]=j-i;
    }
  }
  r=n-k-v;
  for(int i=0; i<=k; i++)
  {
    for(int j=0; j<=v; j++)
    {
      for(int l=0; l<=r; l++)
      {
        if(i>0)
        {
          //debug("0 %d %d %d: %d\n", i-1, j, l, get(0, i-1, j, l));
          dp[i][j][l][0]+=min(dp[i-1][j][l][0], dp[i-1][j][l][2])+get(0, i-1, j, l);
        }
        else
          dp[i][j][l][0]=inf;
        if(j>0)
        {
         // debug("1 %d %d %d: %d\n", i, j-1, l, get(1, i, j-1, l));
          dp[i][j][l][1]+=dp[i][j-1][l][3]+get(1, i, j-1, l);
        }
        else
          dp[i][j][l][1]=inf;
        if(l>0)
        {
         // debug("2 %d %d %d: %d\n", i, j, l-1, get(2, i, j, l-1));
          dp[i][j][l][2]=dp[i][j][l-1][3]+get(2, i, j, l-1);
        }
        else
          dp[i][j][l][2]=inf;
        dp[i][j][l][3]=min(dp[i][j][l][0], min(dp[i][j][l][1], dp[i][j][l][2]));
        for(int qwe=0; qwe<4; qwe++)
          dp[0][0][0][qwe]=0;
      }
    }
  }
  printf("%d\n", dp[k][v][r][3]);
  return 0;
}