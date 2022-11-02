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
const int M=1000005;

int n, m, vi, same;
bool vis[M];
vector<int> V[M];
LL res;
bool loop[M];

void DFS(int v)
{
  vis[v]=1;
  vi++;
  for(int i=0; i<siz(V[v]); i++)
  {
    if(!vis[V[v][i]])
      DFS(V[v][i]);
  }
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    if(a==b)
    {
      same++;
      loop[a]=1;
      //continue;
    }
    V[a].PB(b);
    V[b].PB(a);
  }
  for(int i=1; i<=n; i++)
  {
    if(siz(V[i])!=0)
    {
      DFS(i);
      break;
    }
  }
  for(int i=1; i<=n; i++)
    if(siz(V[i])==0)
      vi++;
  if(vi!=n)
  {
    printf("0\n");
    return 0;
  }
  res+=(LL)same*(LL)(m-same);
  res+=((LL)same*(LL)(same-1))/2;
  for(int i=1; i<=n; i++)
  {
    int edges=V[i].size();
    if(loop[i])
      edges-=2;
    res+=((LL)edges*(LL)(edges-1))/2;
  }
  printf("%lld\n", res);
  return 0;
}