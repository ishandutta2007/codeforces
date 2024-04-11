#include<iostream>
#include<cstdio>
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
int h[100005];
signed main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)h[i]=read()+h[i-1];
		flag=false;
		for(int i=1;i<=n;i++)if(h[i]<i*(i-1)/2)
		{
			flag=true;
			break;
		}
		if(flag==false)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}