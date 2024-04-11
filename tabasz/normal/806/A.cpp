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

int t;

LL countFi(LL x)
{
  LL res = 1;
  for (LL i = 2; i * i <= x; i++)
  {
    if (x % i == 0)
    {
      x /= i;
      LL lol = 1;
      while (x % i == 0)
      {
        lol *= i;
        x /= i;
      }
      res *= lol * (i - 1);
    }
  }
  if (x > 1)
  {
    res *= (x - 1);
  }
  return res;
}

LL poww(LL x, LL p, LL mod)
{
  LL res = 1;
  int i = 30;
  while (i >= 0)
  {
    res = (res * res) % mod;
    if ((p>>i) % 2 == 1)
    {
      
      res = (res * x) % mod;
    }
    i--; 
  }
  return res;
}

LL solve()
{
  LL x, y, p, q;
  scanf("%lld%lld%lld%lld", &x, &y, &p, &q);
  if (p == q)
  {
    if (x == y)
    {
      return 0;
    }
    else
    {
      return -1;
    }
  }
  if (p == 0)
  {
    if (x == 0)
    {
      return 0;
    }
    else
    {
      return -1;
    }
  }
  LL lol = - p * y + x * q;
 // debug("%lld\n", lol);
  if (lol == 0)
  {
    return 0;
  }
  if (lol < 0)
  {
    LL fi = countFi(q - p);
    LL l = ((q - p) - ((-lol) % (q - p))) % (q - p);
    l *= poww(p % (q - p), fi - 1, q - p);
    l %= (q - p);
    LL k = (l * p - lol) / (q - p);
    return l + k;
  }
  else
  {
    LL fi = countFi(p);
    LL k = (p - (lol % p)) % p;
    //debug("kk %lld %lld\n", k, poww(2, 1, 3));
    k *= poww((q - p) % p, fi - 1, p);
    k %= p;
    LL l = (k * (q - p) + lol) / p;
    //debug("%lld %lld %lld %lld\n", p, fi, k, l);
    return k + l;
  }
  
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &t);
  while (t--)
  {
    printf("%lld\n", solve());
  }
  return 0;
}