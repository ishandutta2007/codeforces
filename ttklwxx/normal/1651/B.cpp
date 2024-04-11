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
signed main()
{
	int t,n,cf;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		flag=true;
		cf=1;
		for(int i=1;i<=n-1;i++)
		{
			cf*=3;
			if(cf>1000000000)
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
		printf("YES\n");
		cf=1;
		for(int i=1;i<=n;i++)
		{
			printf("%lld ",cf);
			cf*=3;
		}
		printf("\n");
	}
	return 0;
}