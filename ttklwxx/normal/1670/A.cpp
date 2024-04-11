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
int a[2000005];
signed main()
{
	int t,n,ans;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]<0)
			{
				ans++;
				a[i]=-a[i];
			}
		}
		for(int i=1;i<=ans;i++)a[i]=-a[i];
		flag=true;
		for(int i=1;i<=n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				flag=false;
				break;
			}
		}
		if(flag==true)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}