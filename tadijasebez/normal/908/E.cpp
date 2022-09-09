#include <stdio.h>
#include <map>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int N=1050;
int dp[N][N],sz[N],ans=1;
ll a[N];
char ch[N];
map<ll,int> Map;
map<ll,int>::iterator it;
int main()
{
	int n,m,i,j;
	dp[0][0]=1;
	scanf("%i %i",&m,&n);
	for(i=1;i<=m;i++) for(j=1;j<=i;j++)
	{
		dp[i][j]=(ll)dp[i-1][j]*j%mod+dp[i-1][j-1];
		dp[i][j]%=mod;
		sz[i]+=dp[i][j];
		sz[i]%=mod;
	}
	for(i=0;i<n;i++)
	{
		scanf("%s",&ch);
		for(j=0;j<m;j++) a[j]+=((ll)(ch[j]-'0'))<<i;
	}
	for(j=0;j<m;j++) Map[a[j]]++;
	for(it=Map.begin();it!=Map.end();it++)
	{
		ans=(ll)ans*sz[(it->second)]%mod;
	}
	printf("%i\n",ans);
	return 0;
}