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
const int M = 1e6;

int n;
set<PII> secik[4];
int C[M];
int L[M], R[M];

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  REP(i, n)
  {
    scanf("%d", C + i);
  }
  REP(i, n)
  {
    scanf("%d", L + i);
  }
  REP(i, n)
  {
    scanf("%d", R + i);
  }
  REP(i, n)
  {
    secik[L[i]].insert(MP(C[i],i));
    secik[R[i]].insert(MP(C[i],i));
  }
  int m;
  scanf("%d", &m);
  REP(i, m)
  {
    int a;
    scanf("%d", &a);
    if (secik[a].begin() == secik[a].end())
    {
      printf("-1 ");
    }
    else
    {
      PII lol = *secik[a].begin();
      RE(j, 3)
      {
        secik[j].erase(lol);
      }
      printf("%d ", lol.F);
    }
  }
  printf("\n");
  return 0;
}