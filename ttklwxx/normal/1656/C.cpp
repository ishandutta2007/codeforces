#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
int a[200005],pos[200005];
map<int,int>ma;
int main()
{
	int t,n,k;
	bool flag0,flag1,flag2;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		if(a[1]>=2)
		{
			printf("YES\n");
			continue;
		}
		flag0=false;
		flag1=false;
		flag2=false;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)flag0=true;
			if(a[i]==1)flag1=true;
			if(a[i]==2)flag2=true;
		}
		if(flag0==true&&flag1==true)
		{
			printf("NO\n");
			continue;
		}
		if(flag0==true)
		{
			printf("YES\n");
			continue;
		}
		ma.clear();
		for(int i=1;i<=n;i++)ma[a[i]]=1;
		flag2=false;
		for(int i=1;i<=n;i++)
		{
			if(ma[a[i]+1]==1)
			{
				flag2=true;
				break;
			}
		}
		if(flag2==true)printf("NO\n");
		else printf("YES\n");
	} 
	return 0;
}