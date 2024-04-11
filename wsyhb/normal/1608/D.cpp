#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int qpow(int a,int n)
{
	int res=1;
	while(n)
	{
		if(n&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		n>>=1; 
	}
	return res;
}
inline int C(int n,int m)
{
	assert(n>=0&&m>=0&&n>=m);
	int res=1;
	for(int i=1;i<=m;++i)
		res=1ll*res*i%mod;
	res=qpow(res,mod-2);
	for(int i=n;i>n-m;--i)
		res=1ll*res*i%mod;
	return res;
}
const int max_n=1e5+5;
char d[max_n][5];
int main()
{
	int n;
	scanf("%d",&n);
	int cnt_B=0,cnt_W=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",d[i]);
		for(int k=0;k<=1;++k)
		{
			if(d[i][k]=='B')
				++cnt_B;
			else if(d[i][k]=='W')
				++cnt_W;
		}
	}
	if(cnt_B>n||cnt_W>n)
	{
		puts("0");
		return 0;
	}
	int res=1;
	for(int i=1;i<=n&&res;++i)
	{
		if(d[i][0]=='?'&&d[i][1]=='?')
			res<<=1,res-=res>=mod?mod:0;
		else if(d[i][0]==d[i][1])
			res=0;
	}
	int ans=C(2*n-cnt_B-cnt_W,n-cnt_B)-res;
	ans+=ans<0?mod:0;
	bool flag=true;
	for(int i=1;i<=n;++i)
	{
		if(d[i][0]!='?'&&d[i][0]!='B')
		{
			flag=false;
			break;
		}
		if(d[i][1]!='?'&&d[i][1]!='W')
		{
			flag=false;
			break;
		}
	}
	if(flag)
		++ans,ans-=ans>=mod?mod:0;
	flag=true;
	for(int i=1;i<=n;++i)
	{
		if(d[i][0]!='?'&&d[i][0]!='W')
		{
			flag=false;
			break;
		}
		if(d[i][1]!='?'&&d[i][1]!='B')
		{
			flag=false;
			break;
		}
	}
	if(flag)
		++ans,ans-=ans>=mod?mod:0;
	printf("%d\n",ans);
	return 0;
}