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

int n, ind1, ind2;
int R[100005], T[100005];

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  RE(i, n)
    scanf("%d", T+i);
  printf("%d\n", 20);
  R[1]=20;
  for(int i=2; i<=n; i++)
  {
    R[i]=R[i-1]+20;
    while(T[ind1+1]+90<=T[i])
      ind1++;
    while(T[ind2+1]+1440<=T[i])
      ind2++;
    R[i]=min(R[i], min(R[ind1]+50, R[ind2]+120));
    printf("%d\n", R[i]-R[i-1]);
  }
  return 0;
}