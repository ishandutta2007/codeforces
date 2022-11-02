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

int n;
int T[125][10];
int done[10];

int points(int ind, int all)
{
  if (2 * done[ind] > all)
  {
    return 500;
  }
  if (4 * done[ind] > all)
  {
    return 1000;
  }
  if (8 * done[ind] > all)
  {
    return 1500;
  }
  if (16 * done[ind] > all)
  {
    return 2000;
  }
  if (32 * done[ind] > all)
  {
    return 2500;
  }
  return 3000;
}

int count(int ind, int x)
{
  int res = 0;
  for (int i = 0; i < 5; i++)
  {
    if (T[ind][i] == -1)
    {
      continue;
    }
    res += points(i, n + x) - (points(i, n + x) / 250) * T[ind][i];
  }
  return res;
}

bool check(int x)
{
  REP(i, 5)
  {
    done[i] = 0;
  }
  for (int i = 0; i < 5; i++)
  {
    if (T[1][i] != -1 && (T[2][i] != -1 && T[1][i] >= T[2][i]))
    {
      done[i] += x;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (T[i][j] != -1)
      {
        done[j]++;
      }
    }
  }
  //debug("%d %d %d\n", x, count(1, x), count(2, x));
 //for (int i = 0; i < 5; i++)
 // {
  //  debug("%d ", points(i, n + x));
 // }
 // debug("\n");
  return count(1, x) > count(2, x);
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      scanf("%d", T[i] + j);
    }
  }
  for (int i = 0; i <= 10000; i++)
  {
    if (check(i))
    {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
  /*int st = 0, en = 1e9 + 7, mid = (st + en) / 2, r = 1e9 + 10;
  while (st <= en)
  {
    //debug("%d ", mid);
    if (check(mid))
    {
      //debug("lol\n");
      r = min(r, mid);
      en = mid - 1;
    }
    else
    {
      st = mid + 1;
    }
    mid = (st + en) / 2;
  }
  if (r == 1e9 + 10)
  {
    printf("-1\n");
  }
  else
  {
    printf("%d\n", r);
  }*/
  return 0;
}