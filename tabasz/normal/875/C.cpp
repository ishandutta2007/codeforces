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
const int M = 1024 * 128;

int A[M];
vector<int> V[M], W[M];
int n, m, k;
bool vis[M], cant[M], must[M];

void DFS(int v)
{
  if (vis[v])
  {
    return;
  }
  vis[v] = true;
  for (int i = 0; i < siz(V[v]); i++)
  {
    DFS(V[v][i]);
  }
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    int l;
    scanf("%d", &l);
    for (int j = 0; j < l; j++)
    {
      int a;
      scanf("%d", &a);
      W[i].PB(a);
    }
  }
  bool can = true;
  for (int i = 1; i < n; i++)
  {
    bool boo = false;
    for (int j = 0; j < min(siz(W[i]), siz(W[i - 1])); j++)
    {
      if (W[i][j] == W[i - 1][j])
      {
        continue;
      }
      boo = true;
      if (W[i][j] < W[i - 1][j])
      {
        must[W[i - 1][j]] = true;
        cant[W[i][j]] = true;
        //debug("lol %d %d\n", i, j);
      }
      else
      {
        V[W[i][j]].PB(W[i - 1][j]);
      }
      break;
    }
    if (boo == false && siz(W[i]) < siz(W[i - 1]))
    {
      can = false;
      break;
    }
  }
  if (can == false)
  {
    printf("No\n");
    return 0;
  }
  for (int i = 1; i <= m; i++)
  {
    if (must[i])
    {
      DFS(i);
    }
  }
  for (int i = 1; i <= m; i++)
  {
    if (vis[i] && cant[i])
    {
      can = false;
    }
    if (vis[i])
    {
      k++;
    }
  }
  if (can == false)
  {
    printf("No\n");
    return 0;
  }
  printf("Yes\n%d\n", k);
  for (int i = 1; i <= m; i++)
  {
    if (vis[i])
    {
      printf("%d ", i);
    }
  }
  if (k > 0)
  {
    printf("\n");
  }
  return 0;
}