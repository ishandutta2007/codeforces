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
const int M=1005;
const int inf=2e9;

int n, m, we, res, R[2][M], W[M], B[M];
vector<int> V[M], X[M];
bool vis[M];

void DFS(int v, int in)
{
  //debug("%d %d\n", v, in);
  X[in].PB(v);
  vis[v]=1;
  REP(i, siz(V[v]))
    if(!vis[V[v][i]])
      DFS(V[v][i], in);
}

void add(int w, int b, int ind)
{
  REP(i, we+1)
    if(i+w<=we)
      R[1-ind][i+w]=max(R[1-ind][i+w], R[ind][i]+b);
}

int main()
{
  //ios_base::sync_with_stdio(0);
  REP(j, 2)
    REP(i, M)
      R[j][i]=-inf;
  R[0][0]=0;
  R[1][0]=0;
  scanf("%d%d%d", &n, &m, &we);
  RE(i, n)
    scanf("%d", W+i);
  RE(i, n)
    scanf("%d", B+i);
  REP(i, m)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    V[a].PB(b);
    V[b].PB(a);
  }
  int tmp=0;
  RE(i, n)
  {
    if(!vis[i])
    {
      REP(i, we+1)
        R[1-tmp%2][i]=R[tmp%2][i];
      DFS(i, i);
      PII a=MP(0, 0);
      REP(j, siz(X[i]))
      {
        //debug("%d: %d %d %d %d\n", i, X[i][j], W[X[i][j]], B[X[i][j]], tmp);
        a.F+=W[X[i][j]];
        a.S+=B[X[i][j]];
        add(W[X[i][j]], B[X[i][j]], tmp%2);
      }
      add(a.F, a.S, tmp%2);
      tmp++;
    }
  }
  REP(i, we+1)
  {
    res=max(res, R[tmp%2][i]);
    //debug("%d: %d\n", i, R[tmp%2][i]);
  }
  printf("%d\n", res);
  return 0;
}