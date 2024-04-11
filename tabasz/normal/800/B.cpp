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
#define int LL
const double eps = 1e-9;

int n;
vector<PII> V;
double res = 1e10;

LL sq(LL x)
{
  return x * x;
}

double dist(PII x, PII y)
{
  return sqrt((double)sq(x.F - y.F) + (double)sq(x.S - y.S));
}

LL vect(PII x, PII a, PII b)
{
  return (a.F - x.F) * (b.S - x.S) - (a.S - x.S) * (b.F - x.F);
}

double lineDist(PII a, PII b, PII x)
{
  double len = dist(a, b);
  double st = 0.0, en = 1e10, mid = (st + en) / 2;
  while (en - st > eps)
  {
    if (len * mid <= abs(vect(x, a, b)))
    {
      st = mid;
    }
    else
    {
      en = mid;
    }
    mid = (st + en) / 2;
  }
  //debug("\n\n%d %d, %d %d, %d %d\n", x.F, x.S, a.F - x.F, a.S - x.S, b.F - x.F, b.S - x.S);
  //debug("%lld %lf\n", abs(vect(x, a, b)), st);
  return st / 2;
}

main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%lld", &n);
  REP(i, n)
  {
    int a, b;
    scanf("%lld%lld", &a, &b);
    V.PB(MP(a, b));
  }
  for (int i = 1; i < n; i++)
  {
    res = min(res, dist(V[i - 1], V[i]) / 2);
  }
  V.PB(V[0]);
  V.PB(V[1]);
  //debug("res %lf\n", res);
  for (int i = 0; i < n; i++)
  {
    res = min(res, lineDist(V[i], V[i + 2], V[i + 1]));
  }
  printf("%.8lf\n", res);
  return 0;
}