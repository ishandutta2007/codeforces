#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y)
			printf("%d\n",x+y);
		else
		{
			int b=(y%x)/2;
			int k=(y-2*b)/x;
			long long n=1ll*k*x+b;
			printf("%lld\n",n);
		}
	}
    return 0;
}