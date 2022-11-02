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
const int M = 1024 * 256;

int n, res;
int T[M];
vector<int> V[M];
int dp[M];

void DFS(int v, int prev)
{
  for (int i = 0; i < siz(V[v]); i++)
  {
    if (V[v][i] != prev)
    {
      DFS(V[v][i], v);
      dp[v] += dp[V[v][i]];
    }
  }
  if (dp[v] == 0)
  {
    dp[v] = 1;
  }
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", T + i);
    V[T[i]].PB(i);
    V[i].PB(T[i]);
  }
  DFS(0, -1);
  printf("%d\n", dp[0]);
  return 0;
}