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
int gcd(int a,int b)
{
	while(a^=b^=a^=b%=a);
	return b;
}
int a,b,x;
int solve(int r)
{
	if(r<b)return 0;
	x=r/b-1;
	int ans=(x/a+1)*b;
    if((r/b)%a==0)ans+=r%b+1;
    return r+1-ans;
}
signed main()
{
	int t,q,l,r;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a=read();
		b=read();
		q=read();
		if(a>b)swap(a,b);
		a/=gcd(a,b);
		for(int i=1;i<=q;i++)
		{
			l=read();
			r=read();
			printf("%lld ",solve(r)-solve(l-1));
		}
		printf("\n");
	}
	return 0;
}