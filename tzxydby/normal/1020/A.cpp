#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,h,a,b,k,ta,fa,tb,fb,s;
	scanf("%d%d%d%d%d",&n,&h,&a,&b,&k);
	while(k--)
	{
		scanf("%d%d%d%d",&ta,&fa,&tb,&fb);
		int sum=0;
		if(ta==tb)
		{
			printf("%d\n",abs(fa-fb));
			continue;
		}
		if(fa>=a&&fa<=b)
		{
			s=fa;
			sum=0;
		}
		else if(abs(fa-a)<abs(fa-b))
		{
			s=a;
			sum+=abs(fa-a);
		}
		else
		{
			s=b;
			sum+=abs(fa-b);
		}
		sum+=abs(ta-tb);
		sum+=abs(fb-s);
		printf("%d\n",sum);
	}
	return 0;
}