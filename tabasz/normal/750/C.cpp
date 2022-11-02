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

vector<PII> V;
int n, a, b, sum, maxi;

bool go(int tmp)
{
  REP(i, n)
  {
    if((V[i].S==1 && tmp<1900) || (V[i].S==2 && tmp>=1900))
      return false;
    tmp+=V[i].F;
  }
  return true;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  REP(i, n)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    V.PB(MP(x, y));
    if(y==1)
      a++;
    else
      b++;
    sum+=x;
    if(i<n-1)
      maxi=max(maxi, sum);
  }
  if(b==0)
  {
    printf("Infinity\n");
    return 0;
  }
  if(a==0)
  {
    printf("%d\n", 1899-maxi+sum);
    return 0;
  }
  int tmp=0;
  REP(i, n-1)
  {
    if(V[i].S!=V[i+1].S)
    {
      int st, en;
      if(V[i].S==1)
      {
        st=1900;
        en=1899-V[i].F;
      }
      else
      {
        st=1900-V[i].F;
        en=1899;
      }
      FORD(j, en-tmp, st-tmp)
      {
        if(go(j))
        {
          printf("%d\n", j+sum);
          return 0;
        }
      }
      printf("Impossible\n");
      return 0;
    }
    tmp+=V[i].F;
  }
  return 0;
}