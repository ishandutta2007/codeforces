#include<iostream>
#include<cstdio>
#define int long long
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
int a[200005],b[200005],f[200005][21],mi[200005][21],logg[200005],qz[200005];
signed main()
{
	int n,q,x,y,maxn,minn;
	n=read();
	q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
		qz[i]=qz[i-1]+b[i]-a[i];
		mi[i][0]=f[i][0]=qz[i];
	}
	logg[0]=-1;
	for(int i=1;i<=n;i++)logg[i]=logg[i>>1]+1;
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=n-(1<<j)+1;i++)f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		for(int i=1;i<=n-(1<<j)+1;i++)mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
	}
	for(int i=1;i<=q;i++)
	{
		x=read();
		y=read();
		maxn=max(f[x][logg[y-x+1]],f[y-(1<<logg[y-x+1])][logg[y-x+1]])-qz[x-1];
		minn=min(mi[x][logg[y-x+1]],mi[y-(1<<logg[y-x+1])][logg[y-x+1]])-qz[x-1];
		if(minn<0)printf("-1\n");
		else if(qz[y]-qz[x-1]!=0)printf("-1\n");
		else printf("%lld\n",maxn);
	}
	return 0;
}