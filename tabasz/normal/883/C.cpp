#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define F first
#define S second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB 
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
using namespace std;
const LL inf = 1e18;

LL f, T, mt;
LL t[2], p[2], a[2];

LL get(LL ile, LL czas)
{
  if (ile == 0)
  {
    return 0;
  }
  if (min(ile * mt, ile * t[1]) > czas)
  {
    return inf;
  }
  if (ile * mt <= czas)
  {
    return 0;
  }
  LL st = 0, en = ile, mid = (st + en) / 2, res = inf;
  while (st <= en)
  {
    LL il = min(ile, mid * a[1]);
    if (il * t[1] + (ile - il) * mt <= czas)
    {
      res = min(res, mid);
      en = mid - 1;
    }
    else
    {
      st = mid + 1;
    }
    mid = (st + en) / 2;
  }
  return res * p[1];
}

int main()
{
  scanf("%lld%lld%lld", &f, &T, &mt);
  for (int i = 0; i < 2; i++)
  {
    scanf("%lld%lld%lld", a + i, t + i, p + i);
  }
  if (t[0] > t[1])
  {
    swap(a[0], a[1]);
    swap(t[0], t[1]);
    swap(p[0], p[1]);
  }
  if (min(mt, t[0]) * f > T)
  {
    printf("-1\n");
    return 0;
  }
  if (mt * f <= T)
  {
    printf("0\n");
    return 0;
  }
  LL res = inf;
  for (LL i = 0; (i - 1) * a[0] * t[0] +1 <= T; i++)
  {
    LL ile = min(f, a[0] * i);
    LL cena = i * p[0] + get(f - ile, T - ile * t[0]);
    res = min(res, cena);
  }
  printf("%lld\n", res);
  return 0;
}