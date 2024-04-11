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
const int M = 1024;

int n, c, m;
int T[M];

bool good()
{
  if (T[1] == 0)
  {
    return false;
  }
  for (int i = 2; i <= n; i++)
  {
    if (T[i] == 0 || T[i] < T[i - 1])
    {
      return false;
    }
  }
  return true;
}

int put1(int a)
{
  int ind = 1;
  while (ind < n && T[ind] != 0 && T[ind] <= a)
  {
    ind++;
  }
  T[ind] = a;
  return ind;
}

int put2(int a)
{
  int ind = n;
  while (ind > 1 && T[ind] != 0 && T[ind] >= a)
  {
    ind--;
  }
  T[ind] = a;
  return ind;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d%d", &n, &m, &c);
  for (int i = 0; i < m; i++)
  {
    int a;
    scanf("%d", &a);
    int ind;
    if (a > c / 2)
    {
      ind = put2(a);
    }
    else
    {
      ind = put1(a);
    }
    printf("%d\n", ind);
    fflush(stdout);
    if (good())
    {
      return 0;
    }
  }
  return 0;
}