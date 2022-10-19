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
int main()
{
	int t,n,ans=1;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ans=1;
		while(n+ans>(ans+1)*(ans+2)/2-1)ans++;
		if(n+ans==(ans+1)*(ans+2)/2-2)ans++;
		printf("%d\n",ans);
	}
	return 0;
}