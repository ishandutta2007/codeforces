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
const LL mod=1e9+7;

int n, m, h;
LL p, q;
LL sil[100005], silodw[100005];

LL poww(LL x, LL p)
{
  LL res=1;
  int i=30;
  while(i>=0)
  {
    res=(res*res)%mod;
    if((p>>i)%2==1)
      res=(res*x)%mod;
    i--;
  }
  return res;
}

LL newt(LL a, LL b)
{
  return ((sil[a]*silodw[b]%mod)*silodw[a-b])%mod;
}

LL solve(int now, int f, int w, int ht)
{
  LL res=0;
  int ff=1, ww=1;
  while(ff<=f && ww*ht<=w)
  {
    res+=(newt(f-1, ff-1)*newt(w-ww*(ht-1)-1, ww-1))%mod;
    if(res>=mod)
      res-=mod;
    if(now==0)
      ff++;
    else
      ww++;
    now=1-now;
  }
  return res;
}

int main()
{
  sil[0]=1;
  silodw[0]=1;
  RE(i, 100004)
  {
    sil[i]=(sil[i-1]*i)%mod;
    silodw[i]=poww(sil[i], mod-2);
  }
  //ios_base::sync_with_stdio(0);
  scanf("%d%d%d", &n, &m, &h);
  if (n == 0)
  {
    printf("%d\n", m > h);
    return 0;
  }
  if (m == 0)
  {
    printf("%d\n", n > 0);
    return 0;
  }
  q+=solve(0, n, m, 1);
  q+=solve(1, n, m, 1);
  p+=solve(0, n, m, h+1);
  p+=solve(1, n, m, h+1);
  q%=mod;
  p%=mod;
  //debug("%lld %lld\n", p, q);
  printf("%lld\n", (p*poww(q, mod-2))%mod);
  return 0;
}