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
const int M =1024 * 128;
const int inf = 1e9;

int n, c, d;
int r1 = -inf, r2 = -inf;
int D[2][2 * M];
int rl, rr;

void add(int ind, int v, int w)
{
  v += M;
  D[ind][v] = max(D[ind][v], w);
  while (v > 1)
  {
    v /= 2;
    D[ind][v] = max(D[ind][2 * v], D[ind][2 * v + 1]);
  }
}

int query(int ind, int p, int k)
{
  p += M;
  k += M;
  int r = max(D[ind][p], D[ind][k]);
  while (p / 2 != k / 2)
  {
    if (p % 2 == 0)
    {
      r = max(r, D[ind][p + 1]);
    }
    if (k % 2 == 1)
    {
      r = max(r, D[ind][k - 1]);
    }
    p /= 2;
    k /= 2;
  }
  return r;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d%d", &n, &c, &d);
  REP(i, 2)
  {
    REP(j, 2 * M)
    {
      D[i][j] = -inf;
    }
  }
  REP(i, n)
  {
    int b, p;
    char cc;
    scanf("%d%d %c", &b, &p, &cc);
    if (cc == 'C')
    {
      if (p <= c)
      {
        r1 = max(r1, b);
        rl = max(rl, b + query(0, 0, c - p));
        add(0, p, b);
      }
    }
    else
    {
      if (p <= d)
      {
        r2 = max(r2, b);
        rr = max(rr, b + query(1, 0, d - p));
        add(1, p, b);
      }
    }
  }
  int lol = max(r1 + r2, max(rl, rr));
  if (lol < 0)
  {
    printf("0\n");
  }
  else
  {
    printf("%d\n", lol);
  }
  return 0;
}