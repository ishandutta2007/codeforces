#include<iostream>
#include<cstdio>
#define mod 1000000007
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
int a[10005],sl[5005][5005],tans[5005];
int main()
{
	int n,k,q,x,y,ans;
	n=read();
	k=read();
	q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)sl[0][i]=1;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sl[i][j]=(sl[i-1][j-1]+sl[i-1][j+1])%mod;
		}
	}
	for(int i=0;i<=k;i++)for(int j=1;j<=n;j++)tans[j]=(tans[j]+1LL*sl[i][j]*sl[k-i][j]%mod)%mod;
	ans=0;
	for(int i=1;i<=n;i++)ans=(ans+1LL*tans[i]*a[i]%mod)%mod;
	for(int i=1;i<=q;i++)
	{
		x=read();
		y=read();
		ans=(ans+1LL*tans[x]*((y-a[x])%mod+mod)%mod)%mod;
		a[x]=y;
		printf("%d\n",ans);
	}
	return 0;
}