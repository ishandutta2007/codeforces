#include<iostream>
#include<cstdio>
#include<cstring>
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
char s[200005];
signed main()
{
	int t,a,b;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a=read();
		b=read();
		printf("%lld\n",min(min(a,b),(a+b)/4));
	}
	return 0;
}