#include<iostream>
#include<cstdio>
#include<algorithm>
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
int a[501][501],ans[10001][2];
int main()
{
	int t,n,m,tans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=2;i<=n+m;i++)ans[i][0]=ans[i][1]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				a[i][j]=read();
				if((i+j)<1+(n+m+1)/2)ans[i+j][a[i][j]]++;
				else ans[n+m+2-i-j][a[i][j]]++;
			}
		}
		tans=0;
		for(int i=2;i<=(n+m+1)/2;i++)tans+=min(ans[i][0],ans[i][1]);
		printf("%d\n",tans);
	}
	return 0;
}