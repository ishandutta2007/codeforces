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
const int M=1024*128;

PII D[2*M];
int T[2*M], n;

int get(int v, int rem)
{
  if(D[v].S<=rem)
    return -1;
  if(v>=M)
    return T[v];
  if(D[2*v+1].S>rem)
    return get(2*v+1, rem);
  return get(2*v, rem+D[2*v+1].F-D[2*v+1].S);
}

void add(int v, int w)
{
  v+=M;
  if(w==1)
    D[v].S++;
  else
    D[v].F++;
  while(v>1)
  {
    v/=2;
    if(D[2*v].S>=D[2*v+1].F)
      D[v]=MP(D[2*v].F, D[2*v+1].S+D[2*v].S-D[2*v+1].F);
    else
      D[v]=MP(D[2*v].F+D[2*v+1].F-D[2*v].S, D[2*v+1].S);
  }
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  REP(i, n)
  {
    int a, b, c;
    scanf("%d%d", &a, &b);
    if(b==1)
    {
      scanf("%d", &c);
      add(a, 1);
      T[M+a]=c;
    }
    else
      add(a, -1);
    printf("%d\n", get(1, 0));
  }
  return 0;
}