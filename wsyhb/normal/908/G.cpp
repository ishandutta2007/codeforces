#include<bits/stdc++.h>
using namespace std;
const int max_len=700+5;
char s[max_len];
int n[max_len];
const int mod=1e9+7;
int f[max_len][max_len][2],g[max_len][max_len][2],power[max_len],sum_power[max_len];
inline void add(int &a,int b)
{
	a=a+b-(a+b>=mod?mod:0);
}
inline int get_sum(int a,int b)
{
	return a+b-(a+b>=mod?mod:0);
}
int main()
{
	int T=1,b=10;
	while(T--)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int i=1;i<=len;++i)
			n[i]=s[i]-'0';
		power[0]=sum_power[0]=1;
		for(int i=1;i<=len-1;++i)
		{
			power[i]=1ll*power[i-1]*b%mod;
			sum_power[i]=get_sum(sum_power[i-1],power[i]);
		}
		int ans=0;
		for(int k=1;k<=9;++k)
		{
			f[0][0][0]=1;
			for(int i=1;i<=len;++i)
				for(int j=0;j<=i;++j)
				{
					// f/g[i-1][j-(n[i]>=k)][0] -> f/g[i][j][0]
					f[i][j][0]=f[i][j][1]=g[i][j][0]=g[i][j][1]=0;
					if(j-(n[i]>=k)>=0)
					{
						f[i][j][0]=f[i-1][j-(n[i]>=k)][0];
						g[i][j][0]=(g[i-1][j-(n[i]>=k)][0]+1ll*f[i-1][j-(n[i]>=k)][0]*power[len-i]*n[i])%mod;
					}
					// f/g[i-1][j-(x>=k)][0] -> f/g[i][j][1]
					for(int x=0;x<n[i];++x)
					{
						if(j-(x>=k)>=0)
						{
							add(f[i][j][1],f[i-1][j-(x>=k)][0]);
							g[i][j][1]=(g[i][j][1]+1ll*f[i-1][j-(x>=k)][0]*power[len-i]*x+g[i-1][j-(x>=k)][0])%mod;
						}
					}
					// f/g[i-1][j-(x>=k)][1] -> f/g[i][j][1]
					for(int x=0;x<=b-1;++x)
					{
						if(j-(x>=k)>=0)
						{
							add(f[i][j][1],f[i-1][j-(x>=k)][1]);
							g[i][j][1]=(g[i][j][1]+1ll*f[i-1][j-(x>=k)][1]*power[len-i]*x+g[i-1][j-(x>=k)][1])%mod;
						}
					}
				}
			for(int i=1;i<=len;++i)
				ans=(ans+1ll*(f[len][i][0]+f[len][i][1])*sum_power[i-1])%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}