#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		long long p=1ll*a*d,q=1ll*b*c;
		if(!p&&!q)
			puts("0");
		else if(!p||!q)
			puts("1");
		else
		{
			long long v=gcd(p,q);
			p/=v,q/=v;
			if(p==q)
				puts("0");
			else if(p%q==0||q%p==0)
				puts("1");
			else
				puts("2");
		}
	}
	return 0;
}