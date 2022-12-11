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
		long long prod=1ll*a*b;
		bool exist=false;
		for(int x=a+1;x<=c;++x)
		{
			long long goal=prod/gcd(prod,x);
			int y=d/goal*goal;
			if(y>b)
			{
				printf("%d %d\n",x,y);
				exist=true;
				break;
			}
		}
		if(!exist)
			puts("-1 -1");
	}
	return 0;
}