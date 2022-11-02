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
const LL mod = 1e9 + 7;
const int M = 1024 * 1024;

LL sil[M], odw[M];
LL dp[M];
LL P[M];

LL newt(int n, int k)
{
  LL r = (((sil[n] * odw[k]) % mod) * odw[n - k]) % mod;
  return r;
}

LL poww(LL x, int p)
{
  if (p == 0)
  {
    return 1LL;
  }
  LL r = poww(x, p / 2);
  r = (r * r) % mod;
  if (p % 2)
  {
    r = (r * x) % mod;
  }
  return r;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  int n, k;
  scanf("%d%d", &n, &k);
  sil[0] = 1;
  odw[0] = 1;
  for (int i = 1; i < M; i++)
  {
    sil[i] = (sil[i - 1] * i) % mod;
    odw[i] = poww(sil[i], mod - 2);
  }
  for (int i = k + 2; i <= n; i++)
  {
    LL pref = P[i - 1] - P[i - k - 1];
    if (pref < 0)
    {
      pref += mod;
    }
    pref = (pref * sil[i - 2]) % mod;
    dp[i] = (pref + (LL)(i - k - 1) * sil[i - 2]) % mod;
    P[i] = (P[i - 1] + dp[i] * odw[i - 1]) % mod;
    //debug("%d: %lld %lld %lld\n", i, dp[i], P[i], pref);
  }
  LL res = 0;
  for (int i = 1; i <= n; i++)
  {
    res = (res + dp[i] * ((newt(n - 1, i - 1) * sil[n - i]) % mod)) % mod;
    //debug("%d: %lld\n", i, res);
  }
  printf("%lld\n", res);
  return 0;
}