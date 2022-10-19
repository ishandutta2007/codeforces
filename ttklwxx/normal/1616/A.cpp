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
bool vis[205];
int a[205];
int main()
{
	int t,n,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(!vis[a[i]+100])vis[a[i]+100]=true,ans++;
			else if(!vis[100-a[i]])vis[100-a[i]]=true,ans++;
		}
		for(int i=0;i<=200;i++)vis[i]=false;
		printf("%d\n",ans);
	} 
	return 0;
}