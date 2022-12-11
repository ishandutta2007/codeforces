#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int mx=0,g=0;
		for(int i=1;i<=n;++i)
		{
			int a;
			scanf("%d",&a);
			if(i==1)
				mx=g=a;
			else
			{
				mx=max(mx,a);
				g=__gcd(g,a);
			}
		}
		printf("%d\n",mx/g);
	}
	return 0;
}