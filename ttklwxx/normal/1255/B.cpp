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
int a[2001],pos[2001];
bool bi(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	int t,n,m,ans;
	t=read();
	for(int sth=1;sth<=t;sth++)
	{
		n=read();
		m=read();
		ans=0;
		for(int i=1;i<=n;i++)a[i]=read(),pos[i]=i,ans+=2*a[i];
		if(m<n||n==2)
		{
			printf("-1\n");
			continue;
		}
		sort(pos+1,pos+n+1,bi);
		ans+=(m-n)*(a[pos[1]]+a[pos[2]]);
		printf("%d\n",ans);
		for(int i=1;i<=n-1;i++)printf("%d %d\n",i,i+1);
		printf("%d 1\n",n);
		for(int i=n+1;i<=m;i++)printf("%d %d\n",pos[1],pos[2]);
	}
	return 0; 
}