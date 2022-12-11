#include<bits/stdc++.h>
using namespace std;
const int max_n=2e3+5;
int a[max_n],dp[max_n][2];
const int mod=1e9+7;
inline void add(int &a,int b)
{
	a+=b,a-=a>=mod?mod:0;
}
int main()
{
	int n,h;
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		if(a[i]>h)
		{
			puts("0");
			return 0;
		}
	}
	if(h-a[n]>1)
	{
		puts("0");
		return 0;
	}
	dp[0][0]=1,a[0]=h;
	for(int i=1;i<=n;++i)
	{
		if(!dp[i-1][0]&&!dp[i-1][1])
		{
			puts("0");
			return 0;
		}
		for(int k=0;k<=1;++k)
		{
			int j=h-a[i-1]-k,v=dp[i-1][k];
			if(j<0)
				assert(!v);
			if(v)
			{
				if(h-a[i]==j)
				{
					add(dp[i][0],v);
					if(j>0)
						dp[i][1]=(dp[i][1]+1ll*j*v)%mod;
				}
				else if(h-a[i]==j+1)
				{
					add(dp[i][0],v);
					dp[i][1]=(dp[i][1]+(j+1ll)*v)%mod;
				}
			}
		}
	}
	printf("%d\n",dp[n][h-a[n]]);
	return 0;
}