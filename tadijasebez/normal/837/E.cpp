#include <stdio.h>
#include <algorithm>
using namespace std;
long long min(long long a, long long b){ if(a>b) return b; else return a;}
int main()
{
	long long i,x,y,tmp,tmp1,g,sol=0;
	scanf("%lld %lld",&x,&y);
	while(y)
	{
		g=__gcd(x,y);
		x/=g,y/=g;
		tmp=x,tmp1=y;
		for(i=2;i*i<=x;i++)
		{
			if(tmp%i!=0) continue;
			tmp1=min(tmp1,y%i);
			while(tmp%i==0) tmp/=i;
		}
		if(tmp>1) tmp1=min(tmp1,y%tmp);
		y-=tmp1,sol+=tmp1;
	}
	printf("%lld\n",sol);
	return 0;
}