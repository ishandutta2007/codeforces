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
const int M=1024*1024;

int n, k;
LL res=1;
int D[2*M];

void add(int v, int w)
{
  v+=M;
  D[v]+=w;
  while(v>1)
  {
    v/=2;
    D[v]=D[2*v]+D[2*v+1];
  }
}

int sum(int p, int k)
{
  if(p>k)
    return 0;
  p+=M;
  k+=M;
  int r=D[p];
  if(p!=k)
    r+=D[k];
  while(p/2!=k/2)
  {
    if(p%2==0)
      r+=D[p+1];
    if(k%2==1)
      r+=D[k-1];
    p/=2;
    k/=2;
  }
  return r;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &k);
  k=min(k, n-k);
  add(0, 1);
  int tmp=0;
  REP(i, n)
  {
    int next=(tmp+k)%n, lol=0;
    if(next>tmp)
      lol=sum(tmp+1, next-1);
    else
      lol=sum(0, next-1)+sum(tmp+1, n-1);
    lol++;
    res+=lol;
    tmp=next;
    add(next, 2);
    printf("%lld ", res);
  }
  printf("\n");
  return 0;
}