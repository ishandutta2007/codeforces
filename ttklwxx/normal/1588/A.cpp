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
int sl[10005],slb[10005];
int a[1005],b[1005]; 
int main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=0;i<=1000;i++)sl[i]=0,slb[i]=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			sl[a[i]+100]++; 
		}
		for(int i=1;i<=n;i++)
		{
			b[i]=read();
			slb[b[i]+100]++;
		}
		flag=true;
		for(int i=1000;i>=0;i--)
		{
			if(sl[i]<slb[i])
			{
				sl[i-1]-=slb[i]-sl[i];
				if(sl[i-1]<0)
				{
					flag=false;
					break;
				}
				sl[i]=slb[i];
			}
		}
		for(int i=0;i<=1000;i++)if(sl[i]!=slb[i])flag=false;
		if(flag==false)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}