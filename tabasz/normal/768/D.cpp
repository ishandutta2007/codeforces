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
const double eps=1e-7;

double dp[8001][1001];
int k, q;

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d", &k, &q);
  dp[0][0]=1;
  RE(i, 8000)
  {
    RE(j, k)
    {
      dp[i][j]=dp[i-1][j]*((double)j/(double)k)+dp[i-1][j-1]*((double)(k-j+1)/(double)k);
    }
  }
  REP(i, q)
  {
    int p;
    scanf("%d", &p);
    int res=0;
    while(dp[res][k]<((double)p-eps)/2000.0)
      res++;
    printf("%d\n", res);
  }
  return 0;
}