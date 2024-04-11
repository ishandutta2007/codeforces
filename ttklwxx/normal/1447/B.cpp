#include<iostream>
#include<cstdio>
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
int a[21][21];
int main()
{
	int t,n,m,ans=0,sl=0;
	int minn;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		ans=0;
		sl=0;
		minn=114514;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				a[i][j]=read();
				if(a[i][j]<0)ans+=-a[i][j],sl++,minn=min(minn,-a[i][j]);
				else ans+=a[i][j],minn=min(minn,a[i][j]);
			}
		}
		if(sl%2==1)ans=ans-2*minn;
		printf("%d\n",ans);
	}
	return 0;
}