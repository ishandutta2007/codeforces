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
#define int LL
const int M=200005;

int n;
int T[M], dp[M], dp2[M];
vector<PII> V[M], X;

int get(int dis, int t)
{
  int st=0, en=siz(X)-1, mid=(st+en)/2, r=siz(X)-1;
  while(st<=en)
  {
    if(dis-X[mid].S<=t)
    {
      r=min(r, mid);
      en=mid-1;
    }
    else
      st=mid+1;
    mid=(st+en)/2;
  }
  return r;
}

void DFS(int v, int dist, int prev)
{
  X.PB(MP(v, dist));
  int ind=get(dist, T[v]);
  if(ind<siz(X)-1)
  {
    dp[prev]++;
    dp2[X[ind].F]++;
  }
  REP(i, siz(V[v]))
  {
    if(V[v][i].F!=prev)
    {
      DFS(V[v][i].F, dist+V[v][i].S, v);
      dp[v]+=dp[V[v][i].F];
      dp[v]-=dp2[V[v][i].F];
    }
  }
  X.pb();
}

main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%lld", &n);
  RE(i, n)
    scanf("%lld", T+i);
  FOR(i, 2, n)
  {
    int a, b;
    scanf("%lld%lld", &a, &b);
    V[a].PB(MP(i, b));
    V[i].PB(MP(a, b));
  }
  DFS(1, 0, 0);
  RE(i, n)
    printf("%lld ", dp[i]);
  printf("\n");
  return 0;
}