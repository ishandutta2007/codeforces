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
const int M = 1e5 + 5;

int n, one;
LL T[M];
int P[50], D[50], NP[50];
set<LL> se;

bool check(int x)
{
  int xx = x;
  for (int i = 1; i <= 41; i++)
  {
    D[i] = 0;
  }
  for (int i = 1; i <= 41; i++)
  {
    D[i] = x - P[i];
    x = min(x, P[i]);
  }
  int tmp = 0, tmp2 = 0;
  for (int i = 41; i >= 1; i--)
  {
    tmp += D[i];
    tmp2 += NP[i];
    if (tmp2 > tmp)
    {
    /*if (x == 3)
        {
          debug("aaa");
        }*/
      return false;
    }
  }
  //debug("%d %d %d %d\n", tmp, tmp2, one, xx);
  return (tmp - tmp2) >= one - xx;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  LL lolol = 1;
  while (lolol <= 1e12)
  {
    se.insert(lolol);
    lolol *= 2;
  }
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", T + i);
    if (T[i] == 1)
    {
      one++;
    }
    int lol = 0;
    LL tmp = T[i];
    while (tmp > 1)
    {
      lol++;
      tmp /= 2;
    }
    if (se.find(T[i]) != se.end())
    {
      P[lol]++;
    }
    else
    {
      NP[lol + 1]++;
    }
  }
  int st = 1, en = one, mid = (st + en) / 2, r = en + 1;
  while (st <= en)
  {
    if (check(mid))
    {
    //  debug("tak %d\n", mid);
      r = min(r, mid);
      en = mid - 1;
    }
    else
    {
      //debug("nie %d\n", mid);
      st = mid + 1;
    }
    mid = (st + en) / 2;
  }
  if (r == one + 1)
  {
    printf("-1\n");
  }
  else
  {
    for (int i = r; i <= one; i++)
    {
      printf("%d ", i);
    }
    printf("\n");
  }
  return 0;
}