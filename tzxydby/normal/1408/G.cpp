#include<bits/stdc++.h>
using namespace std;
const int N=1505,mod=998244353;
int n,a[N*N],b[N*N],f[N],sz[N],s[N],dp[N][N],t[N];
int fa(int x){return f[x]==x?x:f[x]=fa(f[x]);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x;
			scanf("%d",&x);
			if(i<j)
				a[x]=i,b[x]=j;
		}
		f[i]=i;
		sz[i]=1;
		dp[i][1]=1;
	}
	for(int i=1;i<=n*(n-1)/2;i++)
	{
		a[i]=fa(a[i]),b[i]=fa(b[i]);
		if(a[i]==b[i])
		{
			s[a[i]]++;
			if(s[a[i]]==sz[a[i]]*(sz[a[i]]-1)/2)
				dp[a[i]][1]=1;
		}
		else
		{
			for(int j=0;j<=n;j++)
				t[j]=0;
			for(int j=0;j<=sz[a[i]];j++)
				for(int k=0;k<=sz[b[i]];k++)
					t[j+k]=(t[j+k]+1ll*dp[a[i]][j]*dp[b[i]][k]%mod)%mod;
			for(int j=0;j<=sz[a[i]]+sz[b[i]];j++)
				dp[a[i]][j]=t[j];
			f[b[i]]=a[i];
			sz[a[i]]+=sz[b[i]];
			s[a[i]]+=s[b[i]]+1;
			if(s[a[i]]==sz[a[i]]*(sz[a[i]]-1)/2)
				dp[a[i]][1]=1;
		}
	}
	int v=fa(1);
	for(int i=1;i<=n;i++)
		printf("%d ",dp[v][i]);
	return 0;
}