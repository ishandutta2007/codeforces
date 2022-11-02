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


int main()
{
  //ios_base::sync_with_stdio(0);
  int n, t, k, d;
  scanf("%d%d%d%d", &n, &t, &k ,&d);
  int tt = ((n + k - 1) / k) * t;
  int t2 = d + t;
  if (t2 < tt)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
  return 0;
}