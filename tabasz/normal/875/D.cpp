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
const int M = 1024 * 256;

int n;
int T[2 * M];
vector<PII> V;
int A[100];
LL res;
int P[50];

void add(int v, int w)
{
  v += M;
  T[v] = max(T[v], w);
  while (v > 1)
  {
    v /= 2;
    T[v] = max(T[2 * v], T[2 * v + 1]);
  }
}

int get(int v, int val)
{
  if (T[v] < val)
  {
    return -1;
  }
  if (v >= M)
  {
    return v - M;
  }
  if (T[2 * v + 1] >= val)
  {
    return get(2 * v + 1, val);
  }
  return get(2 * v, val);
}

int addRes(int val, int st, int en)//all pos
{
  int first = get(1, val);
  //debug("%d %d %d %d\n", val, st, en, first);
  if (first >= en)
  {
    return 0;
  }
  if (first < st)
  {
    return en - st + 1;
  }
  return en - first;
}

int main()
{
  P[0] = 1;
  for (int i = 1; i < 32; i++)
  {
    P[i] = P[i - 1] * 2;
  }
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    int a;
    scanf("%d", &a);
    add(i, a);
    int j = 0;
    while ((a >> j) > 0)
    {
      if ((a >> j) % 2 == 1)
      {
        A[j] = i;
      }
      j++;
    }
    V.clear();
    //debug("%d:\n", i);
    for (int j = 0; j <= 30; j++)
    {
      V.PB(MP(-A[j], j));
    }
    sort(ALL(V));
    for (int j = 0; j <= 30; j++)
    {
      V[j].F *= -1;
      //debug("%d %d\n", V[j].F, V[j].S);
    }
    int ind = 0, val = 0, pos = i;
    while (ind < siz(V))
    {
      while (ind < siz(V) && V[ind].F == pos)
      {
        val += P[V[ind].S];
        ind++;
      }
      res += addRes(val, V[ind].F + 1, pos);
      pos = V[ind].F;
      if (pos == 0)
      {
        break;
      }
    }
   // debug("res = %d\n", res);
  }
  printf("%lld\n", res);
  return 0;
}