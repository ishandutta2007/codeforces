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
const int M = 100005;
const double eps = 1e-7;

int n, p;
PII T[M];
LL sum;

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &p);
  for (int i = 0; i < n; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    sum += a;
    T[i] = MP(a, b);
  }
  if (sum <= p)
  {
    printf("-1\n");
    return 0;
  }
  double st = 0.0, en = 1e18, mid = (st + en) / 2.0;
  while (en - st > eps)
  {
    double get = 0.0;
    for (int i = 0; i < n; i++)
    {
      get += max(mid * T[i].F - T[i].S, 0.0);
    }
    if (get <= mid * p)
    {
      st = mid;
    }
    else
    {
      en = mid;
    }
    mid = (st + en) / 2;
  }
  printf("%lf\n", st);
  return 0;
}