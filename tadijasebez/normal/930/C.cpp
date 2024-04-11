#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100050;
int dp[N][2];
int a[N],b[N];
int BIT[N];
int max(int a, int b){ return a>b?a:b;}
void Init(){ for(int i=0;i<N;i++) BIT[i]=0;}
void Set(int i, int f){ for(i++;i<N;i+=i&-i) BIT[i]=max(BIT[i],f);}
int Get(int i){ int ret=0;for(i++;i;i-=i&-i) ret=max(ret,BIT[i]);return ret;}
int main()
{
	int n,m,l,r,i;
	scanf("%i %i",&n,&m);
	while(n--) scanf("%i %i",&l,&r),a[l]++,a[r+1]--;
	bool all=1;
	for(i=1;i<=m;i++) b[i]=b[i-1]+a[i];
	for(i=2;i<=m;i++) if(b[i]!=b[i-1]) all=0;
	dp[1][0]=0;
	for(i=2;i<=m;i++)
	{
		dp[i][0]=Get(b[i])+1;
		Set(b[i],dp[i][0]);
	}
	Init();
	dp[m][1]=0;
	for(i=m-1;i;i--)
	{
		dp[i][1]=Get(b[i])+1;
		Set(b[i],dp[i][1]);
	}
	int sol=0;
	for(i=1;i<=m;i++) sol=max(sol,dp[i][0]+dp[i][1]+1);
	if(sol==m && !all) sol--;
	printf("%i\n",sol);
	return 0;
}