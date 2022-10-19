#include<iostream>
#include<cstdio>
#include<algorithm>
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
int a[1005][21];
int qz[1005];
int het[1000005],cnt;
signed main()
{
	int n,k;
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			a[i][j]=read();
		}
		qz[i]=0;
		for(int j=1;j<=k;j++)
		{
			qz[i]=qz[i]*3+a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		//if(qz[i]==0)continue;
		for(int j=i+1;j<=n;j++)
		{
			//if(qz[j]==0)continue;
			het[++cnt]=0;
			for(int sth=1;sth<=k;sth++)
			{
				het[cnt]=het[cnt]*3+(a[i][sth]+a[j][sth])%3;
			}
			//if(het[cnt]==3)printf("orz%lld %lld\n",i,j);
		}
	}
	for(int i=1;i<=n;i++)
	{
		qz[i]=0;
		for(int j=1;j<=k;j++)
		{
			qz[i]=qz[i]*3+(3-a[i][j])%3;
		}
	}
	sort(qz+1,qz+n+1);
	sort(het+1,het+cnt+1);
	int x=1,y=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		while(x<=cnt&&het[x]<qz[i])x++;
		while(y<=cnt&&het[y]<=qz[i])y++;
		//printf("%lld %lld\n",x,y);
		//printf("%lld\n",qz[i]);
		if(y>x)ans+=(y-x)*(y-x-1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}