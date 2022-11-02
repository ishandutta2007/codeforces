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

int n, k;
bool B[2*M];
vector<int> V;
int dist[2*M];

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &k);
  for(int i=0; i<k; i++)
  {
    int a;
    scanf("%d", &a);
    B[a]=1;
  }
  if(B[n])
  {
    printf("1\n");
    return 0;
  }
  for(int i=0; i<=1000; i++)
  {
    if(B[i])
      V.PB(i-n);
  }
  queue<int> Q;
  for(int i=0; i<siz(V); i++)
  {
    Q.push(1000+V[i]);
    dist[1000+V[i]]=1;
  }
  while(!Q.empty())
  {
    int v=Q.front();
    Q.pop();
    for(int i=0; i<siz(V); i++)
    {
      if(v+V[i]<0 || v+V[i]>2000)
        continue;
      if(dist[v+V[i]]==0)
      {
        dist[v+V[i]]=dist[v]+1;
        Q.push(v+V[i]);
      }
    }
  }
  if(dist[1000]==0)
  {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", dist[1000]);
  return 0;
}