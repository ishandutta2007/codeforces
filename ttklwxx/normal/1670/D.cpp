#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
int calc(int n)
{
	int x=n/3,y=(n+1)/3,z=(n+2)/3;
	return x*(y+z)+y*(x+z)+z*(x+y);
}
signed main()
{
	int t,n,l,r,mid;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		l=1;
		r=200000;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(calc(mid)>=n)r=mid-1;
			else l=mid+1;
		} 
		printf("%lld\n",l);
	}
	return 0;
}