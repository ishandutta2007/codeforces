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

int n, k;

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &k);
  if(n==2 || n==3)
  {
    printf("-1\n");
    return 0;
  }
  if(k==1 || k>3)
  {
    printf("-1\n");
    return 0;
  }
  if(k==2)
  {
    if(n==4)
      printf("-1\n");
    else
    {
      printf("%d\n", n-1);
      RE(i, n-1)
        printf("%d %d\n", i, i+1);
    }
    return 0;
  }
  if(k==3)
  {
    int r=((n-2)*(n-3))/2+2;
    printf("%d\n", r);
    for(int i=1; i<n-1; i++)
      for(int j=i+1; j<n-1; j++)
        printf("%d %d\n", i, j);
    printf("%d %d\n%d %d\n", n-2, n-1, n-1, n);
  }
  return 0;
}