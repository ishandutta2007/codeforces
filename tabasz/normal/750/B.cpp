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

int n;

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  int h=20000;
  REP(i, n)
  {
    int a;
    char C[10];
    scanf("%d%s", &a, C);
    if(h==20000 && C[0]!='S')
    {
      printf("NO\n");
      return 0;
    }
    if(h==0 && C[0]!='N')
    {
      printf("NO\n");
      return 0;
    }
    if(C[0]=='S')
    {
      if(h<a)
      {
        printf("NO\n");
        return 0;
      }
      h-=a;
    }
    if(C[0]=='N')
    {
      if(h+a>20000)
      {
        printf("NO\n");
        return 0;
      }
      h+=a;
    }
  }
  if(h==20000)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}