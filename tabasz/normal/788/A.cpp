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
const int M=100005;

int n;
int T[M];

LL solve(vector<int> V)
{
  LL res=0, tmp=0;
  for(int i=0; i<siz(V); i++)
  {
    tmp+=V[i];
    res=max(res, tmp);
    if(tmp<0)
      tmp=0;
  }
  return res;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  REP(i, n)
  {
    int a;
    scanf("%d", &a);
    T[i]=a;
  }
  vector<int> V, X;
  for(int i=1; i<n; i++)
  {
    int lol=abs(T[i]-T[i-1]);
    if(i%2)
    {
      V.PB(lol);
      X.PB(-lol);
    }
    else
    {
      V.PB(-lol);
      X.PB(lol);
    }
  }
  LL res=max(solve(V), solve(X));
  printf("%lld\n", res);
  return 0;
}