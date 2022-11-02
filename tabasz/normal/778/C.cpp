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
const int M=300*1005;

int V[M][30];
char C[10];
int dep[M], si[M], n, R[M], maxdep;
vector<PII> X;
int PD[M], D[M];

void DFS(int v, int d)
{
  maxdep=max(maxdep, d);
  dep[v]=d;
  si[v]=1;
  REP(i, 26)
  {
    if(V[v][i]!=0)
    {
      DFS(V[v][i], d+1);
      si[v]+=si[V[v][i]];
    }
  }
}

int go(int v, int mir)
{
  int r=0;
  if(v==mir)
    r++;
  REP(i, 26)
  {
    if(V[v][i]!=0)
    {
      if(V[mir][i]==0)
      {
        V[mir][i]=V[v][i];
        X.PB(MP(mir, i));
      }
      r+=go(V[v][i], V[mir][i]);
    }
  }
  return r;
}

int count(int v)
{
  X.clear();
  int res=0;
  if(si[v]==1)
    return 1;
  int ind=0, size=-1;
  REP(i, 26)
  {
    if(V[v][i]!=0 && si[V[v][i]]>size)
    {
      ind=i;
      size=si[V[v][i]];
    }
  }
  res+=si[V[v][ind]];
  REP(i, 26)
    if(V[v][i]!=0 && i!=ind)
      res+=go(V[v][i], V[v][ind]);
  REP(i, siz(X))
    V[X[i].F][X[i].S]=0;
  return res;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  REP(i, n-1)
  {
    int a, b;
    scanf("%d%d%s", &a, &b, C);
    V[a][(int)C[0]-(int)'a']=b;
    
  }
  DFS(1, 1);
  RE(i, n)
    D[dep[i]]++;
  RE(i, n)
    PD[i]=PD[i-1]+D[i];
  RE(i, n)
  {
    //debug("count(%d)=%d, %d, %d\n", i, count(i), dep[i], si[i]);
    R[dep[i]]+=count(i);
  }
  int res=n, tmp=0;
  RE(i, maxdep-1)
  {
    if(R[i]+PD[i-1]<res)
    {
      res=R[i]+PD[i-1];
      tmp=i;
    }
  }
  printf("%d\n%d\n", res, tmp);
  return 0;
}