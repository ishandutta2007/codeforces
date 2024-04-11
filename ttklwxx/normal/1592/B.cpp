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
int a[200005],b[200005];
int main()
{
	int t,n,x,sl=0;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		x=read();
		for(int i=1;i<=n;i++)a[i]=read(),b[i]=a[i];
		if(x*2<=n)
		{
			printf("YES\n");
			continue;
		} 
		sort(b+1,b+n+1);
		flag=true;
		for(int i=n-x+1;i<=x;i++)
		{
			if(a[i]!=b[i])
			{
				flag=false;
				break;
			}
		}
		if(flag==false)
		{
			printf("NO\n");
			continue;
		}
		else printf("YES\n");
	} 
	return 0;
}