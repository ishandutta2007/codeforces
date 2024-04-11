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

int n, res;
int T[200005], R[200005];
vector<int> V[200005];

void DFS(int v, int prev, int col, int par)
{
  R[v]=col;
  int tmp=1;
  REP(i, siz(V[v]))
  {
    if(V[v][i]!=prev)
    {
      while(tmp==R[v] || tmp==par)
        tmp++;
      DFS(V[v][i], v, tmp, R[v]);
      tmp++;
    }
  } 
}


int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  REP(i, n-1)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    T[a]++;
    T[b]++;
    V[a].PB(b);
    V[b].PB(a);
  }
  RE(i, n)
    res=max(res, T[i]+1);
  DFS(1, 0, 1, 0);
  printf("%d\n", res);
  RE(i, n)
    printf("%d ", R[i]);
  printf("\n");
  return 0;
}