#include<iostream>
#include<cstdio>
#include<cstring>
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
int main()
{
	int t,n,x,ans;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		x=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ans=0;
		flag=true;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=x)continue;
			flag=false;
			for(int j=1;j<=n-1;j++)if(a[j]>a[j+1])
			{
				flag=true;
				break;
			}
			if(flag==false)
			{
				printf("%d\n",ans);
				break;
			}
			swap(a[i],x);
			ans++;
		}
		if(flag==false)continue;
		flag=false;
		for(int i=1;i<=n-1;i++)if(a[i]>a[i+1])
		{
			flag=true;
			break;
		}
		if(flag==false)printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}