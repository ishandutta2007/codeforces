#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=20050;
const int inf=N*100;
pair<int,int> a[N];
bool comp(pair<int,int> a, pair<int,int> b)
{
	if(a.second==b.second) return a.first>b.first;
	else return a.second<b.second;
}
int dp[2][N],c,p=1;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,l,r,i,j,m=0;
	scanf("%i %i %i",&n,&l,&r);
	for(i=1;i<=n;i++) scanf("%i",&a[i].first),m+=a[i].first;
	for(i=1;i<=n;i++) scanf("%i",&a[i].second);
	l=m-l;
	r=m-r;
	l^=r;r^=l;l^=r;
	sort(a+1,a+1+n,comp);
	for(i=1;i<=m;i++) dp[p][i]=-inf;
	dp[p][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=m;j++) dp[c][j]=-inf;
		for(j=0;j<=m;j++)
		{
			int tmp=dp[p][j];
			if(a[i].second==1 && j+a[i].first>=l && j+a[i].first<=r) tmp++;
			dp[c][j+a[i].first]=max(dp[c][j+a[i].first],tmp);
			dp[c][j]=max(dp[c][j],dp[p][j]);
		}
		c^=1;
		p^=1;
	}
	int ans=0;
	for(i=0;i<=m;i++) ans=max(ans,dp[p][i]);
	printf("%i\n",ans);
	return 0;
}