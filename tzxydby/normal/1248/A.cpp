#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,x;
		long long a1=0,a2=0,b1=0,b2=0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&x);
			if(x&1)
				a1++;
			else
				a2++; 
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&x);
			if(x&1)
				b1++;
			else
				b2++; 
		}
		printf("%I64d\n",a1*b1+a2*b2);
	}
	return 0;
}