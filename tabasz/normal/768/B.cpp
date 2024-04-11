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

LL getlen(LL num)
{
  LL res=1;
  while(num>1)
  {
    num/=2;
    res=2*res+1;
  }
  return res;
}

LL solve(LL num, LL lef, LL rig)
{
  if(num==1)
  {
    if(lef<=1 && rig>=1)
      return 1;
    else
      return 0;
  }
  LL half=num/2, mid=num%2, res=0, len=getlen(half);
  if(len>=lef)
    res+=solve(half, lef, rig);
  if(lef<=len+1 && rig>=len+1)
    res+=mid;
  if(rig>len+1)
    res+=solve(half, max(1LL, lef-len-1), rig-len-1);
  //debug("%lld %lld %lld %lld %lld %lld res= %lld\n", num, lef, rig, half, mid, len, res);
  return res;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  LL n, l, r;
  scanf("%lld%lld%lld", &n, &l, &r);
  if(n==0)
  {
    printf("0\n");
    return 0;
  }
  printf("%lld\n", solve(n, l, r));
  return 0;
}