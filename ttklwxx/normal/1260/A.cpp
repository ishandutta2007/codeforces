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
    int n,c,sum;
	n=read();
	for(int i=1;i<=n;i++)
	{
		c=read();
		sum=read();
		printf("%I64d\n",(sum%c)*(sum/c+1)*(sum/c+1)+(c-sum%c)*(sum/c)*(sum/c));
	} 
    return 0;
}