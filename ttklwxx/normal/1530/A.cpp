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
char str[200005];
int main()
{
	int t,n,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ans=0;
		while(n>0)
		{
			ans=max(ans,n%10);
			n/=10;
		}
		printf("%d\n",ans);
	}
	return 0;
}