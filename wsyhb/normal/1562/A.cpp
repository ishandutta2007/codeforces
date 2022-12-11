#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(l<=(r+1)/2)
		{
			int b=(r+1)/2,a=2*b-1;
			assert(r>=a&&a>=b&&b>=l);
			printf("%d\n",a%b);
		}
		else
		{
			int a=r,b=l;
			printf("%d\n",a%b);
		}
	}
    return 0;
}