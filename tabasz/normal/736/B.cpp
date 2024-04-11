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

vector<int> P;
bool B[1000005];

void sito()
{
  for(int i=2; i<100000; i++)
  {
    if(!B[i])
    {
      P.PB(i);
      for(int j=i+i; j<100000; j+=i)
        B[j]=1;
    }
  }
}

bool composite(int x)
{
  int ind=0;
  while(P[ind]*P[ind]<=x)
  {
    if(x%P[ind]==0)
      return true;
    ind++;
  }
  return false;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  /*dp[1]=1000000;
  dp[2]=1;
  for(int i=3; i<=100; i++)
  {
    int maxi=0;
    for(int j=1; j<i; j++)
    {
      if(i%j==0)
        maxi=max(maxi, j);
    }
    dp[i]=maxi;
    //printf("%d: %d\n", i, dp[i]);
    for(int j=2; j<i; j++)
      dp[i]=min(dp[i], dp[j]+dp[i-j]);
    if(dp[i]==3)
      printf("%d\n", i);*/
    sito();
    int n;
    scanf("%d", &n);
    if(!composite(n))
    {
      printf("1\n");
      return 0;
    }
    if(n<=10 || n%2==0)
    {
      printf("2\n");
      return 0;
    }
    int tmp=n-1, x=1;
    while(x<3)
    {
      if(composite(tmp))
        x++;
      else
        x=0;
      tmp--;
    }
    tmp+=3;
    //debug("%d\n", tmp);
    int lol=n%tmp;
    if(lol%2==1)
      printf("2\n");
    else
      printf("3\n");
  return 0;
}