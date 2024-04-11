#include<stdio.h>
#include<iostream>
using namespace std;
int t,n,m;
int ok(long long u)
{
	long long q=m*u,l=1,d=1;
	for(int i=1;i<=u;i++)
	{
		d=d*(u-i+1)/i;
		if(i*d<=q)
			q-=i*d,l+=d;
		else
		{
			l+=q/i;
			break;
		}
		if(l>=n)
			return 1;
	}
	return l>=n;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&m);
		int l=0,r=n-1;
		while(l<r)
		{
			int u=l+r>>1;
			if(ok(u))
				r=u;
			else
				l=u+1;
		}
		printf("%d\n",l);
	}
}