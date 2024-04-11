#include<iostream>
#include<cstdio>
#define mod 998244353
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char s[200005];
int jc[200005],njc[200005];
inline int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		n=1LL*n*n%mod;
		k>>=1;
	}
	return ans;
}
int main()
{
	int t,n,x;
	t=read();
	jc[0]=1;
	for(int i=1;i<=100000;i++)jc[i]=1LL*i*jc[i-1]%mod;
	njc[100000]=ksm(jc[100000],mod-2);
	for(int i=99999;i>=0;i--)njc[i]=1LL*(i+1)*njc[i+1]%mod;
	int sl,sy;
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		sl=0;
		sy=0;
		x=1;
		while(x<=n)
		{
			if(s[x]=='0')
			{
				sl++;
				x++;
			}
			else if(x+1<=n&&s[x+1]=='1')
			{
				sy++;
				x+=2;
			}
			else x++;
		}
		printf("%d\n",1LL*jc[sy+sl]*njc[sy]%mod*njc[sl]%mod);
	}
	return 0;
}