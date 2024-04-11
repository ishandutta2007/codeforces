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
struct bbian
{
	int u,v;
}a[400004],b[400004];
bool bi(struct bbian x,struct bbian y)
{
	if(x.u!=y.u)return x.u<y.u;
	return x.v<y.v;
}
int pri[400004],cnt;
bool vis[400004];
int main()
{
	for(int i=2;i<=400000;i++)
	{
		if(!vis[i])
		{
			pri[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*pri[j]<=40000;j++)
		{
			vis[i*pri[j]]=true;
			if(i%pri[j]==0)break;
		}
	}
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		a[i].u=read();
		a[i].v=read();
		if(a[i].u>a[i].v)swap(a[i].u,a[i].v);
	}
	sort(a+1,a+m+1,bi);
	bool flag;
	for(int i=1;i<n;i++)
	{
		if(n%i!=0)continue;
		if(vis[n/i]==true)continue;
		for(int j=1;j<=m;j++)
		{
			b[j].u=(a[j].u+i-1)%n+1;
			b[j].v=(a[j].v+i-1)%n+1;
			if(b[j].u>b[j].v)swap(b[j].u,b[j].v);
		}
		sort(b+1,b+m+1,bi);
		flag=false;
		for(int j=1;j<=m;j++)
		{	
			if(a[j].u!=b[j].u||a[j].v!=b[j].v)
			{
				flag=true;
				break;
			}
		}
		if(flag==false)
		{
			printf("Yes\n");
			return 0;
		}
	} 
	printf("No\n");
	return 0;
}