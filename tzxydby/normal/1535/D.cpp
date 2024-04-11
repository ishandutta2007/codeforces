#include<bits/stdc++.h>
using namespace std;
const int N=600005;
int n,k,q,f[N],dp[N],lc[N],rc[N],fa[N],x,y,h;
char s[N],b[10];
int main()
{
	scanf("%d%s",&k,s+1);
	n=(1<<k);
	x=1,y=n+1;
	for(int i=1;i<n;i++)
	{
		lc[y]=x;
		f[x]=y;
		x++;
		rc[y]=x;
		f[x]=y;
		x++;
		y++;
	}
	for(int i=1;i<=n;i++)
		dp[i]=1;
	for(int i=n+1;i<n+n;i++)
	{
		if(s[i-n]=='0')
			dp[i]=dp[lc[i]];
		if(s[i-n]=='1')
			dp[i]=dp[rc[i]];
		if(s[i-n]=='?')
			dp[i]=dp[lc[i]]+dp[rc[i]];
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%s",&h,b);
		h+=n;
		s[h-n]=b[0];
		for(int i=h;i;i=f[i])
		{
			if(s[i-n]=='0')
				dp[i]=dp[lc[i]];
			if(s[i-n]=='1')
				dp[i]=dp[rc[i]];
			if(s[i-n]=='?')
				dp[i]=dp[lc[i]]+dp[rc[i]];
		}
		printf("%d\n",dp[n+n-1]);
	}
	return 0;
}