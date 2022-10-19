#include<bits/stdc++.h>
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
int pos[200005],rk[200005];
bool bi(int x,int y)
{
	return a[x]>a[y];
}
bool bibi(int x,int y)
{
	return x>y;
}
int ans[1005][1005];
int main()
{
	int t,m,tk,maxn;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		m=read();
		tk=read();
		for(int i=1;i<=tk;i++)a[i]=read(),pos[i]=i;
		maxn=0;
		for(int i=1;i<=tk;i++)maxn=max(maxn,a[i]);
		sort(pos+1,pos+tk+1,bi);
		for(int i=1;i<=tk;i++)rk[i]=pos[i];
		sort(a+1,a+tk+1,bibi);
		for(int i=1;;i++)
		{
			if(i*i-(i/2)*(i/2)<m||maxn>i*((i+1)/2))continue;
			printf("%d\n",i);
			int now=1;
			while(now<=tk&&a[now]==0)now++;
			for(int j=1;j<=i;j++)for(int k=1;k<=i;k++)ans[j][k]=0;
			for(int j=2;j<=i;j+=2)
			{
				for(int k=1;k<=i;k+=2)
				{
					ans[j][k]=now;
					if(now==tk+1)ans[j][k]=0;
					a[now]--;
					while(now<=tk&&a[now]==0)now++;
				}
			}
			for(int j=1;j<=i;j+=2)
			{
				for(int k=1;k<=i;k+=2)
				{
					ans[j][k]=now;
					if(now==tk+1)ans[j][k]=0;
					a[now]--;
					while(now<=tk&&a[now]==0)now++;
				}
			}
			for(int j=1;j<=i;j+=2)
			{
				for(int k=2;k<=i;k+=2)
				{
					ans[j][k]=now;
					if(now==tk+1)ans[j][k]=0;
					a[now]--;
					while(now<=tk&&a[now]==0)now++;
				}
			}
			for(int j=1;j<=i;j++)
			{
				for(int k=1;k<=i;k++)
				{
					if(ans[j][k]==0)printf("%d ",ans[j][k]);
					else printf("%d ",rk[ans[j][k]]);
				}
				printf("\n");
			}
			break;
		}
	}
	return 0;
}