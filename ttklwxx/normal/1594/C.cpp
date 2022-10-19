#include<iostream>
#include<cstdio>
#define int long long
#define mod 1000000007
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
char str[400005];
signed main()
{
	int t,n,k,ans=0,ch;
	bool flag0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ch=getchar();
		while(ch<'a'||ch>'z')ch=getchar();
		scanf("%s",str+1);
		flag0=true;
		for(int i=1;i<=n;i++)if(str[i]!=ch)
		{
			flag0=false;
			break;
		}
		if(flag0==true)
		{
			printf("0\n");
			continue;
		}
		flag0=true;
		for(int i=(n+2)/2;i<=n;i++)if(str[i]==ch)
		{
			printf("1\n%d\n",i);
			flag0=false;
			break;
		}
		if(flag0==false)continue;
		
			printf("2\n%d ",n);
			for(int j=2;j<=n;j++)if(n%j!=0)
			{
				printf("%d\n",j);
				break;
			}
		
	}
	return 0;
}