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

int n, T[105];
LL res=1;
int vis[105];

int DFS(int v, int w)
{
  if(vis[v]==w)
  {
    if(v==w)
      return 0;
    else
      return -1000000000;
  }
  vis[v]=w;
  return 1+DFS(T[v], w);
}

LL nww(LL a, LL b)
{
  return a*(b/__gcd(a, b));
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  RE(i, n)
    scanf("%d", T+i);
  RE(i, n)
  {
    int x=DFS(i, i);
    //debug("%d %d\n", x, i);
    if(x<0)
    {
      printf("-1\n");
      return 0;
    }
    if(x>0)
    {
      if(x%2==0)
        res=nww(res, x/2);
      else
        res=nww(res, x);
    }
  }
  printf("%lld\n", res);
  return 0;
}