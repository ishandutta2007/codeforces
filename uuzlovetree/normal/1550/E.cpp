#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,k;
char s[maxn];
char a[maxn];
int lst[19][maxn];
int dp[maxn];
const int inf = 1000000000;
bool check(int x)
{
	for(int c=0;c<k;++c)
	{
		for(int i=1;i<=n;++i)a[i]=s[i];
		for(int i=1;i<=n;++i)if(a[i]=='?')a[i]=c+'a';
		int len=0,st=0;
		for(int i=1;i<=n;++i)
		{
			if(a[i]==c+'a')
			{
				len++;
				if(len>=x)st=i-x+1;
			}
			else
			{
				len=0;
			}
			lst[c][i]=st;
		}
	}
	for(int S=0;S<(1<<k);++S)dp[S]=inf;
	dp[0]=0;
	for(int S=0;S<(1<<k);++S)if(dp[S]!=inf)
	{
		for(int c=0;c<k;++c)if(!(S&(1<<c)))
		{
			int l=dp[S],r=n,ans=inf;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(lst[c][mid]>dp[S])ans=mid,r=mid-1;
				else l=mid+1;
			}
			dp[S|(1<<c)]=min(dp[S|(1<<c)],ans);
		}
	}
	if(dp[(1<<k)-1]!=inf)return 1;
	else return 0;
}
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int L=0,R=n,ans=0;
	while(L<=R)
	{
		int M=(L+R)>>1;
		if(check(M))ans=M,L=M+1;
		else R=M-1;
	}
	printf("%d\n",ans);
}