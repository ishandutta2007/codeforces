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
int a[200005],pos[200005],pl[200005];
bool bi(int x,int y)
{
	return a[x]<a[y];
}
signed main()
{
	int t,n,k,sth,gre;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)a[i]=read(),pl[i]=i;
		sort(pl+1,pl+n+1,bi);
		for(int i=1;i<=n;i++)pos[i]=pl[i];
		sth=1;
		flag=false;
		for(int i=1;i<=k;i++)
		{
			gre=pos[sth];
			while(sth<=n&&gre<=n&&gre==pos[sth])
			{
				sth++;
				gre++;
			}
			if(sth>n)
			{
				flag=true;
				break;
			}
		}
		if(flag==true)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}