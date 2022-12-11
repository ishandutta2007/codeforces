#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
char s[maxn];
int a[maxn];
int dp[maxn][2][3];
int maxv[2][3];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)a[i]=s[i]-'0';
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		dp[i][a[i]][0]=1;
		dp[i][a[i]][0]=max(dp[i][a[i]][0],maxv[a[i]^1][0]+1);
		dp[i][a[i]][1]=max(maxv[a[i]][0]+1,maxv[a[i]^1][1]+1);
		dp[i][a[i]][2]=max(maxv[a[i]][1]+1,maxv[a[i]^1][2]+1);
		maxv[a[i]][0]=max(maxv[a[i]][0],dp[i][a[i]][0]);
		maxv[a[i]][1]=max(maxv[a[i]][1],dp[i][a[i]][1]);
		maxv[a[i]][2]=max(maxv[a[i]][2],dp[i][a[i]][2]);
		ans=max(ans,max(max(maxv[a[i]][0],maxv[a[i]][1]),maxv[a[i]][2]));
	}
	printf("%d\n",ans);
	return 0;
}