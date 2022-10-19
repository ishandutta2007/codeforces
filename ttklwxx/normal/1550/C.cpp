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
int a[200005];
int sta[200005],ql,zx[200005],zd[200005],yx[200005],yd[200005];
int yl[200005];
signed main()
{
	int t,n,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)
		{
			zx[i]=0;
			zd[i]=0;
			yx[i]=0;
			yd[i]=0;
			yl[i]=1;
		}
		ql=0;
		for(int i=n;i>=1;i--)
		{
			while(ql>0&&a[sta[ql]]>=a[i])
			{
				zx[sta[ql]]=i;
				ql--;
			}
			sta[++ql]=i;
		}
		ql=0;
		for(int i=n;i>=1;i--)
		{
			while(ql>0&&a[sta[ql]]<=a[i])
			{
				zd[sta[ql]]=i;
				ql--;
			}
			sta[++ql]=i;
		}
		ql=0;
		for(int i=1;i<=n;i++)
		{
			while(ql>0&&a[sta[ql]]>=a[i])
			{
				yx[sta[ql]]=i;
				ql--;
			}
			sta[++ql]=i;
		}
		ql=0;
		for(int i=1;i<=n;i++)
		{
			while(ql>0&&a[sta[ql]]<=a[i])
			{
				yd[sta[ql]]=i;
				ql--;
			}
			sta[++ql]=i;
		}
		for(int i=1;i<=n;i++)yl[i]=1;
		for(int i=1;i<=n;i++)
		{
			yl[yd[i]]=max(yl[yd[i]],zx[i]+1);
			yl[yx[i]]=max(yl[yx[i]],zd[i]+1);
		}
		for(int i=2;i<=n;i++)yl[i]=max(yl[i],yl[i-1]);
		ans=0;
		for(int i=1;i<=n;i++)ans+=(i-yl[i]+1);
		printf("%lld\n",ans);
	}
	return 0;
}