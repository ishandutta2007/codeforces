#include<bits/stdc++.h>
using namespace std;
const int max_len=100+5;
char str[max_len];
const int max_v=8+5;
const int max_U=1<<4|5;
int n[max_len],dp[max_len][max_v][max_U][max_v][max_U][2];
const int mod=998244353;
inline void add(int &a,int b)
{
	a+=b,a-=a>=mod?mod:0;
}
int main()
{
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;++i)
	{
		n[i]=str[len-1-i]^'0';
//		fprintf(stderr,"i=%d n[i]=%d\n",i,n[i]);
	}
	int ans=0;
	for(int a=1;a<=9;++a)
		for(int b=a+1;b<=9;++b)
		{
			if(__gcd(a,b)>1)
				continue;
			int sz=9/b,U=(1<<sz)-1;
			for(int i=0;i<=9;++i)
			{
				int now,r,v1,S1,v2,S2;
				now=i*a,v1=now/10,r=now%10,S1=(r>0&&r%a==0&&r/a<=sz?1<<(r/a-1):0);
				now=i*b,v2=now/10,r=now%10,S2=(r>0&&r%b==0?1<<(r/b-1):0);
				++dp[0][v1][S1][v2][S2][r>n[0]];
			}
			for(int i=0;i+1<len;++i)
				for(int v1=0;v1<=8;++v1)
					for(int S1=0;S1<=U;++S1)
						for(int v2=0;v2<=8;++v2)
							for(int S2=0;S2<=U;++S2)
								for(int k=0;k<=1;++k)
								{
									int v=dp[i][v1][S1][v2][S2][k];
									if(!v)
										continue;
									for(int j=0;j<=9;++j)
									{
										int now,r,v1_new,S1_new,v2_new,S2_new;
										now=v1+j*a,v1_new=now/10,r=now%10,S1_new=S1|(r>0&&r%a==0&&r/a<=sz?1<<(r/a-1):0);
										now=v2+j*b,v2_new=now/10,r=now%10,S2_new=S2|(r>0&&r%b==0?1<<(r/b-1):0);
										int k_new=(r>n[i+1]?1:(r==n[i+1]?k:0));
										add(dp[i+1][v1_new][S1_new][v2_new][S2_new][k_new],v);
									}
								}
			for(int S1=0;S1<=U;++S1)
				for(int S2=0;S2<=U;++S2)
				{
					if(S1&S2)
						add(ans,dp[len-1][0][S1][0][S2][0]);
				}
			for(int i=0;i<len;++i)
				for(int v1=0;v1<=8;++v1)
					for(int S1=0;S1<=U;++S1)
						for(int v2=0;v2<=8;++v2)
							for(int S2=0;S2<=U;++S2)
								for(int k=0;k<=1;++k)
									dp[i][v1][S1][v2][S2][k]=0;
		}
	ans<<=1,ans-=ans>=mod?mod:0;
	int Pow=1;
	for(int i=0;i<len;++i)
	{
		ans=(ans+1ll*Pow*n[i])%mod;
		Pow=10ll*Pow%mod;
	}
	printf("%d\n",ans);
	return 0;
}