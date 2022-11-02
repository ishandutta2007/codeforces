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

int N[55];
int n, k;
char C[5]; 

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &k);
  for(int i=0; i<k-1; i++)
  	N[i]=i;
  for(int i=k-1; i<n; i++)
  {
  	scanf("%s", C);
  	if(C[0]=='Y')
  	{
  			N[i]=i;
  	}
  	else
  	{
  		 N[i]=N[i-k+1];
  	}
  }
  for(int i=0; i<n; i++)
  {
    printf("%c%c ", (char)((int)'A'+N[i]/26), (char)((int)'a'+N[i]%26));
  }
  printf("\n");
  return 0;
}