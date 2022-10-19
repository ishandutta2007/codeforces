#include<iostream>
#include<cstdio>
#include<cstring>
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
int a[200005],b[200005];
bool vis[200005];
int you[200005],my[200005],cy,cm;
int main()
{
	int t,n,x,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		cy=0;
		cm=0;
		ans=0;
		for(int i=1;i<=n;i++)vis[i]=false;
		for(int i=1;i<=n;i++)
		{
			if(!vis[a[i]])
			{
				vis[a[i]]=true;
				b[i]=a[i];
				ans++;
			}
			else
			{
				you[++cy]=i;
			}
		}
		for(int i=1;i<=n;i++)if(!vis[i])my[++cm]=i;
		if(cy==1&&you[1]==my[1])
		{
			b[you[1]]=a[you[1]];
			for(int i=1;i<=n;i++)if(a[i]==a[you[1]]&&i!=you[1])b[i]=you[1];
		}
		else
		{
			for(int i=1;i<=cy;i++)
			{
				if(you[i]==my[i])
				{
					if(i==1)x=2;
					else x=1;
					b[you[i]]=my[x];
					b[you[x]]=my[i];
					if(i==1)i++,my[1]=my[2];
					else my[x]=my[i];
				}
				else b[you[i]]=my[i];
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}