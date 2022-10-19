#include<bits/stdc++.h>
using namespace std;
const int N=44000,M=172,D=20;
int n,d[D],nx[N][D];
long long dp[D][D][N];
bool h[D][N];
bitset<M>a[N];
unordered_map<bitset<M>,int>mp;
long long rd()
{
	char c=getchar();long long x=0;
	while(!(c>='0'&&c<='9'))
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}
long long sol(long long x,int k)
{
	if(x==0)
		return 1;
	int m=0;
	while(x)
	{
		d[m++]=x%10;
		x/=10;
	}
	long long ans=0;
	int u=1;
	for(int i=m-1;i>=0;i--)
	{
		for(int j=0;j<d[i]+(i==0);j++)
			ans+=dp[i][k][nx[u][j]];
		u=nx[u][d[i]];
	}
	return ans;
}
int main()
{
	bitset<M>c;
	c[0]=1,mp[c]=1,a[1]=c,h[0][1]=1,n=1;
	for(int i=1;i<D;i++)
	{
		for(int u=1;u<=n;u++)
		{
			if(h[i-1][u])
			{
				for(int j=0;j<10;j++)
				{
					if(!nx[u][j])
					{
						if(j==0)
							nx[u][j]=u;
						else
						{
							c=0;
							for(int k=j;k<M;k++)
								if(a[u][k])
									c[k-j]=1;
							for(int k=0;k<M-j;k++)
								if(a[u][k])
									c[k+j]=1;
							for(int k=1;k<j;k++)
								if(a[u][k])
									c[j-k]=1;
							if(mp.count(c))
								nx[u][j]=mp[c];
							else
							{
								nx[u][j]=mp[c]=++n;
								a[n]=c;
							}
						}
					}
					h[i][nx[u][j]]=1;
				}
			}
		}
	}
	for(int j=1;j<=n;j++)
	{
		int k=0;
		for(k=0;k<10;k++)
			if(a[j][k])
				break;
		for(;k<10;k++)
			dp[0][k][j]=1;
	}
	for(int j=1;j<D-1;j++)
		for(int k=1;k<=n;k++)
			if(h[D-1-j][k])
				for(int i=0;i<10;i++)
					for(int l=0;l<10;l++)
						dp[j][l][k]+=dp[j-1][l][nx[k][i]];
	int t=rd();
	while(t--)
	{
		long long l=rd(),r=rd();
		int k=rd();
		printf("%lld\n",sol(r,k)-sol(l-1,k));
	}
	return 0;
}