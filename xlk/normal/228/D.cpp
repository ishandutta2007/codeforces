#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,m;
struct BIT
{
	long long c[100020];
	void R(int x,long long y)
	{
		for(;x<=n;x+=x&-x)
			c[x]+=y;
	}
	long long G(int x)
	{
		long long _=0;
		for(;x;x-=x&-x)
			_+=c[x];
		return _;
	}
}a[7][12];
int b[100020];
long long S(int x,int y)
{
	if(y%(2*x-2)==0)
		return 2;
	if(y%(2*x-2)<=x)
		return y%(2*x-2);
	return 2*x-y%(2*x-2);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",b+i);
		for(int j=2;j<7;j++)
			for(int k=0;k<2*j-2;k++)
				a[j][k].R(i,S(j,i+2*j-2-k)*b[i]);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int o,l,r,w,z;
		scanf("%d",&o);
		if(o==1)
		{
			scanf("%d %d",&l,&w);
			for(int j=2;j<7;j++)
				for(int k=0;k<2*j-2;k++)
					a[j][k].R(l,S(j,l+2*j-2-k)*(w-b[l]));
			b[l]=w;
		}
		else
		{
			scanf("%d %d %d",&l,&r,&z);
			printf("%I64d\n",a[z][(l-1)%(2*z-2)].G(r)-a[z][(l-1)%(2*z-2)].G(l-1));
		}
	}
	return 0;
}