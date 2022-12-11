#include<bits/stdc++.h>
using namespace std;
const int mod=10007;
const int max_len=200+5;
char s[max_len];
int dp[max_len][max_len][max_len];
const int max_sz=399+5;
struct Matrix
{
	int v[max_sz][max_sz];
}A,now,res;
int sz;
long long tmp[max_sz][max_sz];
inline Matrix operator * (const Matrix &a,const Matrix &b)
{
	static Matrix res;
	for(int i=1;i<=sz;++i)
		for(int k=i;k<=sz;++k)
		{
			int v=a.v[i][k];
			if(v)
			{
				for(int j=k;j<=sz;++j)
					tmp[i][j]+=v*b.v[k][j];
			}
		}
	for(int i=1;i<=sz;++i)
		for(int j=i;j<=sz;++j)
		{
			res.v[i][j]=tmp[i][j]>=mod?tmp[i][j]%mod:tmp[i][j];
			tmp[i][j]=0;
		}
	return res;
}
int main()
{
	int n;
	scanf("%s%d",s+1,&n);
	int len=strlen(s+1),N=len+n;
	for(int l=1;l<=len;++l)
		for(int L=1;L+l-1<=len;++L)
		{
			int R=L+l-1;
			if(L==R)
				dp[L][R][0]=1;
			else
			{
				if(s[L]==s[R])
				{
					if(R-L==1)
						dp[L][R][0]=1;
					else
					{
						for(int i=0;i<=len-1;++i)
							dp[L][R][i]=dp[L+1][R-1][i];
					}
				}
				else
				{
					for(int i=1;i<=len-1;++i)
					{
						dp[L][R][i]=dp[L+1][R][i-1]+dp[L][R-1][i-1];
						dp[L][R][i]-=dp[L][R][i]>=mod?mod:0;
					}
				}
			}
		}
	int c1=len-1,c2=(len+1)>>1;
	sz=c1+(c2<<1);
	for(int i=1;i+1<=c1+c2;++i)
		A.v[i][i+1]=now.v[i][i+1]=1;
	for(int i=c1+1;i<=c1+c2;++i)
		A.v[i][i+c2]=now.v[i][i+c2]=1;
	for(int i=1;i<=c1;++i)
		A.v[i][i]=now.v[i][i]=24;
	for(int i=c1+1;i<=c1+c2;++i)
		A.v[i][i]=now.v[i][i]=25;
	for(int i=c1+c2+1;i<=sz;++i)
		A.v[i][i]=now.v[i][i]=26;
	for(int i=1;i<=sz;++i)
		res.v[i][i]=1;
	int t=(N+1)/2-1;
	while(t>0)
	{
		if(t&1)
			res=res*now;
		now=now*now;
		t>>=1;
	}
	long long ans=0;
	if(N&1)
	{
		for(int n24=len&1;n24<=len-1;n24+=2)
		{
			int v=dp[1][len][n24];
			if(v)
			{
				int n25=(len-n24+1)>>1;
				int sta=c1+1-n24;
				int goal=c1+n25;
				ans-=v*res.v[sta][goal];
			}
		}
	}
	res=res*A;
	for(int n24=0;n24<=len-1;++n24)
	{
		int v=dp[1][len][n24];
		if(v)
		{
			int n25=(len-n24+1)>>1;
			int sta=c1+1-n24;
			int goal=c1+n25+c2;
			ans+=v*res.v[sta][goal];
		}
	}
	ans=(ans%mod+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}