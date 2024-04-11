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
const int M = 200005;

int n, m, res, fi;
vector<int> V[M];
bool B[M];
vector<int> R, P;
vector<PII> dp;

void countFi()
{
  int mm = m;
  fi = 1;
  for (int i = 2; i <= mm; i++)
  {
    if (mm % i != 0)
    {
      continue;
    }
    int tmp = 1;
    while (mm % i == 0)
    {
      mm /= i;
      tmp *= i;
    }
    fi *= (tmp / i) * (i - 1);
  }
}

LL poww(LL x, LL p)
{
  LL res = 1;
  int i = 20;
  while (i >= 0)
  {
    res = (res * res) % m;
    if ((p>>i) % 2 == 1)
    {
      res = (res * x) % m;
    }
    i--;
  }
  return res;
}

int get(int to, int from)
{
  int gc = __gcd(to, from);
  to /= gc;
  from /= gc;
  //debug("%d %d %d\n", from, fi - 1, poww(from, fi - 1));
  return ((LL)to * poww(from, fi - 1)) % m;
}

void makeRes()
{
  int lol = 0;
  if (B[0] == false)
  {
    lol = 1;
  }
  printf("%d\n", siz(R) + lol);
  int prev = 1;
  for (int i = siz(R) - 1; i >= 0; i--)
  {
    //debug("%d %d: %d\n", prev, R[i], get(R[i], prev));
    printf("%d ", get(R[i], prev));
    prev = R[i];
  }
  if (B[0] == false)
  {
    printf("0 ");
  }
  printf("\n");
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &m);
  countFi();
  //debug("fi %d\n", fi);
  for (int i = 0; i < n; i++)
  {
    int a;
    scanf("%d", &a);
    B[a] = true;
  }
  for (int i = 1; i < m; i++)
  {
    //debug("%d egaefeafb %d\n", i, m);
    if (B[i] == false)
    {
      V[__gcd(i, m)].PB(i);
      //debug("         %d %d\n", i, __gcd(i, m));
    }
  }
  for (int i = 1; i < m; i++)
  {
    if (!V[i].empty())
    {
      P.PB(i);
      dp.PB(MP(siz(V[i]), -1));
      //debug("%d %d\n", i, siz(V[i]));
    }
  }
  for (int i = 0; i < siz(dp); i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (P[i] % P[j] == 0 && dp[j].F + siz(V[P[i]]) > dp[i].F)
      {
        dp[i] = MP(dp[j].F + siz(V[P[i]]), j);
      }
    }
    res = max(res, dp[i].F);
    //debug("dp[%d]: %d\n", i, dp[i].F);
  }
  for (int i = 0; i < siz(dp); i++)
  {
    if (dp[i].F == res)
    {
      int tmp = i;
      while (tmp != -1)
      {
        for (int j = 0; j < siz(V[P[tmp]]); j++)
        {
          R.PB(V[P[tmp]][j]);
        }
        tmp = dp[tmp].S;
      }
      break;
    }
  }
  for (int i = 0; i < siz(R); i++)
  {
    //debug ("%d\n", R[i]);
  }
  makeRes();
  return 0;
}