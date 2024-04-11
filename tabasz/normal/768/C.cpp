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

int n, k, x, mini=10000, maxi;
int A[2][1050];

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d%d", &n, &k, &x);
  REP(i, n)
  {
    int a;
    scanf("%d", &a);
    A[0][a]++;
  }
  RE(i, k)
  {
    REP(j, 1030)
      A[i%2][j]=0;
    int done=0;
    REP(j, 1030)
    {
      int fir=(A[1-i%2][j]+1)/2;
      int sec=A[1-i%2][j]/2;
      if(done%2==0)
      {
        A[i%2][j^x]+=fir;
        A[i%2][j]+=sec;
      }
      else
      {
        A[i%2][j^x]+=sec;
        A[i%2][j]+=fir;
      }
      done+=A[1-i%2][j];
    }
  }
  REP(i, 1030)
  {
    if(A[k%2][i]>0)
    {
      mini=min(mini, i);
      maxi=max(maxi, i);
    }
  }
  printf("%d %d\n", maxi, mini);
  return 0;
}