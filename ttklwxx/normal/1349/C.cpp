#include<iostream>
#include<cstdio>
#define mod 998244353
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
int f[1005][1005],a[1005][1005];
char str[1005][1005];
int qux[2000005],quy[2000005],ql,qr;
int x[5]={0,1,-1,0,0},y[5]={0,0,0,1,-1};
signed main()
{
	int n,m,t,xx,yy,zz;
	n=read();
	m=read();
	t=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str[i]+1);
		for(int j=1;j<=m;j++)a[i][j]=str[i][j]-'0',f[i][j]=1e18;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=4;k++)
			{
				if(1<=i+x[k]&&i+x[k]<=n&&1<=j+y[k]&&j+y[k]<=m&&a[i][j]==a[i+x[k]][j+y[k]])
				{
					f[i][j]=0;
					qux[++qr]=i;
					quy[qr]=j;
				}
			}
	    }
	}
	while(ql<qr)
	{
		xx=qux[++ql];
		yy=quy[ql];
		for(int k=1;k<=4;k++)
		{
			if(1<=xx+x[k]&&xx+x[k]<=n&&1<=yy+y[k]&&yy+y[k]<=m&&f[xx+x[k]][yy+y[k]]==1e18)
            {
            	f[xx+x[k]][yy+y[k]]=f[xx][yy]+1;
            	qux[++qr]=xx+x[k];
            	quy[qr]=yy+y[k];
			}
    	}
    }
    for(int i=1;i<=t;i++)
    {
    	xx=read();
    	yy=read();
    	zz=read();
    	if(zz<=f[xx][yy]||(zz-f[xx][yy])%2==0)printf("%lld\n",a[xx][yy]);
    	else printf("%lld\n",1-a[xx][yy]);
	}
	return 0;
}