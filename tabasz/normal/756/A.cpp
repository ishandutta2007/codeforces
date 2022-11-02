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
int T[1000005];
bool vis[1000005];

void DFS(int v)
{
  vis[v]=1;
  if(!vis[T[v]])
    DFS(T[v]);
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  RE(i, n)
    scanf("%d", T+i);
  int res=0, aa=0;
  RE(i, n)
  {
    int a;
    scanf("%d", &a);
    if(a)
      aa++;
  }
  RE(i, n)
  {
    if(!vis[i])
    {
      DFS(i);
      res++;
    }
  }
  if(res==1)
    res=0;
  if(aa%2==0)
    res++;
  printf("%d\n", res);
  return 0;
}