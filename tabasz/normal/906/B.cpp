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

int n, m;
vector<vector<int>> V;
bool boo = false;

void addodd(int i)
{
  for (int j = m; j > 0; j--)
  {
    if (j % 2 == 1)
    {
      if (!boo)
      {
        V[i].PB(i * m + j);
      }
      else
      {
        V[i].PB((j - 1) * n + i + 1);
      }
    }
  }
}

void addeven(int i)
{
  for (int j = m; j > 0; j--)
  {
    if (j % 2 == 0)
    {
      if (!boo)
      {
        V[i].PB(i * m + j);
      }
      else
      {
        V[i].PB((j - 1) * n + i + 1);
      }
    }
  }
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &m);
  if (n <= 3 && m <= 3)
  {
    if (n == 1 && m == 1)
    {
      printf("YES\n1\n");
      return 0;
    }
    if (n == 3 && m == 3)
    {
      printf("YES\n5 9 4\n1 7 3\n6 2 8\n");
      return 0;
    }
    printf("NO\n");
    return 0;
  }
  if (m < 4)
  {
    boo = true;
    swap(n, m);
  }
  for (int i = 0; i < n; i++)
  {
    V.PB(vector<int>());
    if (m % 2 == 0)
    {
      addodd(i);
      addeven(i);
      if (i % 2 == 1)
      {
        reverse(ALL(V[i]));
      }
    }
    else
    {
      if (i % 2 == 1)
      {
        addodd(i);
        addeven(i);
      }
      else
      {
        addeven(i);
        addodd(i);
      }
    }
  }
  printf("YES\n");
  if (boo)
  {
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        printf("%d ", V[j][i]);
      }
      printf("\n");
    }
  }
  else
  {
    for (int j = 0; j < n; j++)
    {
      for (int i = 0; i < m; i++)
      {
        printf("%d ", V[j][i]);
      }
      printf("\n");
    }
  }
  return 0;
}